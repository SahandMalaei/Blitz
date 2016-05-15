#include "Blitz_Graphics.h"
/* ----------------------------------------------------------------------------------- */
#include <map>
#include <string>
/* ----------------------------------------------------------------------------------- */
#include "GL/glew.h"
#include "FreeImage/FreeImage.h"
/* ----------------------------------------------------------------------------------- */
namespace
{
	typedef blitz::Uint32 Shader, ShaderProgram;
	/* ------------------------------------------------------------------------------- */
	GLuint vertexBufferObject, indexBufferObject;
	std::map<std::string, blitz::graphics::Texture> textureList;
	/* ------------------------------------------------------------------------------- */
	blitz::Int32 createShader(const char *source, blitz::Uint32 glShaderType,
		Shader *out_shaderObject);
	blitz::Int32 createShaderProgram(Shader *shaderList, blitz::Int32 shaderCount,
		ShaderProgram *out_shaderProgram);
	void setVertexFormat();
	void unsetVertexFormat();
}
/* ----------------------------------------------------------------------------------- */
namespace blitz
{
	namespace graphics
	{
		ColorRgb::ColorRgb() :
			r(0.0f),
			g(0.0f),
			b(0.0f)
		{
		}
		ColorRgb::ColorRgb(const ColorRgb &color) :
			r(color.r),
			g(color.g),
			b(color.b)
		{
		}
		ColorRgb::ColorRgb(float r, float g, float b) :
			r(r),
			g(g),
			b(b)
		{
		}
		ColorRgb & ColorRgb::operator =(const ColorRgb &color)
		{
			r = color.r;
			g = color.g;
			b = color.b;
			return *this;
		}
		/* --------------------------------------------------------------------------- */
		ColorRgba::ColorRgba() :
			r(0.0f),
			g(0.0f),
			b(0.0f),
			a(0.0f)
		{
		}
		ColorRgba::ColorRgba(const ColorRgba &color) :
			r(color.r),
			g(color.g),
			b(color.b),
			a(color.a)
		{
		}
		ColorRgba::ColorRgba(float r, float g, float b, float a) :
			r(r),
			g(g),
			b(b),
			a(a)
		{
		}
		ColorRgba & ColorRgba::operator =(const ColorRgba &color)
		{
			r = color.r;
			g = color.g;
			b = color.b;
			a = color.a;
			return *this;
		}
		/* --------------------------------------------------------------------------- */
		Vertex::Vertex()
		{
		}
		Vertex::Vertex(const math::Vec3 position, const ColorRgba &color,
			const math::Vec2 textureCoordinates) :
			position(position),
			color(color),
			textureCoordinates(textureCoordinates)
		{
		}
		Vertex::Vertex(const Vertex &vertex) :
			position(vertex.position),
			color(vertex.color),
			textureCoordinates(vertex.textureCoordinates)
		{
		}
		Vertex & Vertex::operator =(const Vertex &vertex)
		{
			position = vertex.position;
			color = vertex.color;
			textureCoordinates = vertex.textureCoordinates;
			return *this;
		}
		/* --------------------------------------------------------------------------- */
		void clear(const ColorRgba &color)
		{
			glClearColor(color.r, color.g, color.b, color.a);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}
		void draw(Vertex *vertexList, Int32 vertexCount,
			Uint32 *indexList, Int32 indexCount)
		{
			glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferObject);
			glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertexCount, vertexList, GL_DYNAMIC_DRAW);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indexCount, indexList, GL_DYNAMIC_DRAW);
			setVertexFormat();
			glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);
			unsetVertexFormat();
		}
		Int32 loadTexture(const char *fileAddress, Texture *out_texture)
		{
			auto existingTexture = textureList.find(std::string(fileAddress));
			if (existingTexture != textureList.end())
			{
				*out_texture = existingTexture->second;
				return 0;
			}
			FREE_IMAGE_FORMAT freeImageFormat;
			freeImageFormat = FreeImage_GetFileType(fileAddress, 0);
			if (freeImageFormat == FIF_UNKNOWN)
			{
				freeImageFormat = FreeImage_GetFIFFromFilename(fileAddress);
			}
			if (freeImageFormat == FIF_UNKNOWN)
			{
				return 1;
			}
			Bool loadAlphaChannel = 0;
			switch (freeImageFormat)
			{
			case FIF_BMP:
			case FIF_GIF:
			case FIF_JPEG:
				loadAlphaChannel = 0;
				break;
			case FIF_DDS:
			case FIF_PNG:
			case FIF_TARGA:
				loadAlphaChannel = 1;
				break;
			}
			if (FreeImage_FIFSupportsReading(freeImageFormat) == 0)
			{
				return 1;
			}
			FIBITMAP *freeImageBitmap = FreeImage_Load(freeImageFormat, fileAddress, 0);
			if (freeImageBitmap == 0)
			{
				return 1;
			}
			BYTE *imageData = FreeImage_GetBits(freeImageBitmap);
			if (imageData == 0)
			{
				return 1;
			}
			Int32 imageWidth = FreeImage_GetWidth(freeImageBitmap),
				imageHeight = FreeImage_GetHeight(freeImageBitmap);
			if (imageWidth <= 0 || imageHeight <= 0)
			{
				return 1;
			}
			glGenTextures(1, out_texture);
			glBindTexture(GL_TEXTURE_2D, *out_texture);
			GLint imageFormat = loadAlphaChannel ? GL_BGRA : GL_BGR;
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, imageWidth, imageHeight, 0,
				imageFormat, GL_UNSIGNED_BYTE, imageData);
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glBindTexture(GL_TEXTURE_2D, 0);
			FreeImage_Unload(freeImageBitmap);
			std::pair<std::string, Texture> newPair =
				std::pair<std::string, Texture>(fileAddress, *out_texture);
			textureList.insert(newPair);
			return 0;
		}
		void unloadTexture(Texture texture)
		{
			Bool textureExists = 0;
			for (auto listIterator = textureList.begin();
				listIterator != textureList.end(); ++listIterator)
			{
				if (listIterator->second == texture)
				{
					textureList.erase(listIterator);
					textureExists = 1;
					break;
				}
			}
			if (!textureExists)
			{
				return;
			}
			glDeleteTextures(1, &texture);
		}
	}
}
/* ----------------------------------------------------------------------------------- */
namespace
{
	blitz::Int32 createShader(const char *source, blitz::Uint32 glShaderType,
		Shader *out_shader)
	{
		Shader shader = glCreateShader(glShaderType);
		if (shader == 0)
		{
			return 1;
		}
		GLint sourceLength = strlen(source);
		glShaderSource(shader, 1, (const char **)(&source), &sourceLength);
		glCompileShader(shader);
		GLint success;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (success == 0)
		{
			return 1;
		}
		*out_shader = shader;
		return 0;
	}
	blitz::Int32 createShaderProgram(Shader *shaderList, blitz::Int32 shaderCount,
		ShaderProgram *out_shaderProgram)
	{
		ShaderProgram shaderProgram = glCreateProgram();
		for (blitz::Int32 i = 0; i < shaderCount; ++i)
		{
			glAttachShader(shaderProgram, shaderList[i]);
		}
		glLinkProgram(shaderProgram);
		GLint success = 0;
		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
		if (success == 0)
		{
			return 1;
		}
		glValidateProgram(shaderProgram);
		success = 0;
		glGetProgramiv(shaderProgram, GL_VALIDATE_STATUS, &success);
		if (success == 0)
		{
			return 1;
		}
		*out_shaderProgram = shaderProgram;
		return 0;
	}
	void setVertexFormat()
	{
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, 0, sizeof(blitz::graphics::Vertex), 0);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 4, GL_FLOAT, 0, sizeof(blitz::graphics::Vertex),
			(void *)(sizeof(blitz::math::Vec3)));
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 2, GL_FLOAT, 0, sizeof(blitz::graphics::Vertex),
			(void *)(sizeof(blitz::math::Vec3) + 4 * sizeof(float)));
	}
	void unsetVertexFormat()
	{
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		glDisableVertexAttribArray(2);
	}
}