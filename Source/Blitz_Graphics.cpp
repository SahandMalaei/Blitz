#include "Blitz_Graphics.h"
#include "Blitz_Graphics_Core__.h"
/* ----------------------------------------------------------------------------------- */
#include <map>
#include <string>
/* ----------------------------------------------------------------------------------- */
#include "GL/glew.h"
#include "FreeImage/FreeImage.h"
/* ----------------------------------------------------------------------------------- */
#include "Blitz_Graphics_Camera.h"
/* ----------------------------------------------------------------------------------- */
namespace
{
	typedef blitz::Uint32 Shader, ShaderProgram;
	/* ------------------------------------------------------------------------------- */
	ShaderProgram shaderProgram;
	GLuint vertexBuffer, indexBuffer;
	std::map<std::string, blitz::graphics::Texture> textureList;
	blitz::Int32 objectTransformLocation, viewTransformLocation,
		projectionTransformLocation, textureSamplerLocation, useTextureLocation;
	blitz::graphics::Camera *currentCamera = 0;
	/* ------------------------------------------------------------------------------- */
	const char * const DEFAULT_VERTEX_SHADER_SOURCE =
		"#version 140\n\
		\n\
		in vec3 position;\n\
		in vec4 color;\n\
		in vec2 textureCoordinates;\n\
		\n\
		uniform mat4 objectTransform, viewTransform, projectionTransform;\n\
		\n\
		out vec4 fragmentColor;\n\
		out vec2 fragmentTextureCoordinates;\n\
		\n\
		void main()\n\
		{\n\
			gl_Position = projectionTransform * viewTransform * objectTransform *\n\
				vec4(position, 1.0f);\n\
			fragmentColor = color;\n\
			fragmentTextureCoordinates = textureCoordinates;\n\
		}";
	/* ------------------------------------------------------------------------------- */
	const char * const DEFAULT_FRAGMENT_SHADER_SOURCE =
		"#version 140\n\
		\n\
		in vec4 fragmentColor;\n\
		in vec2 fragmentTextureCoordinates;\n\
		\n\
		out vec4 color;\n\
		\n\
		uniform sampler2D textureSampler;\n\
		uniform bool useTexture;\n\
		\n\
		void main()\n\
		{\n\
			if (useTexture)\n\
			{\n\
				color = fragmentColor *\n\
					texture2D(textureSampler, fragmentTextureCoordinates);\n\
			}\n\
			else\n\
			{\n\
				color = fragmentColor;\n\
			}\n\
		}";
	/* ------------------------------------------------------------------------------- */
	blitz::Int32 createShader(Shader *out_shader, const char *source,
		blitz::Uint32 glShaderType);
	blitz::Int32 createShaderProgram(ShaderProgram *out_shaderProgram,
		Shader *shaderList, blitz::Int32 shaderCount);
	blitz::Int32 getShaderUniformVariableLocation(const char *identifier);
	/* ------------------------------------------------------------------------------- */
	blitz::Int32 setInitialRenderStates();
	blitz::Int32 initDefaultShaders();
	blitz::Int32 initDefaultShadersUniformVariables();
	void updateDefaultShadersUniformVariables();
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
		ColorRgba::ColorRgba(const ColorRgb &colorRgb, float a) :
			r(colorRgb.r),
			g(colorRgb.g),
			b(colorRgb.b),
			a(a)
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
			glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
			glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertexCount, vertexList,
				GL_DYNAMIC_DRAW);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Uint32) * indexCount,
				indexList, GL_DYNAMIC_DRAW);
			__setVertexFormat();
			glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);
			__unsetVertexFormat();
		}
		Int32 loadTexture(Texture *out_texture, const char *fileAddress)
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
		void setTexture(Texture texture)
		{
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, texture);
			if (texture != 0)
			{
				glUniform1i(useTextureLocation, 1);
			}
			else
			{
				glUniform1i(useTextureLocation, 0);
			}
		}
		void unsetTexture()
		{
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, 0);
			glUniform1i(useTextureLocation, 0);
		}
		void setObjectTransform(const math::Mat44 &transform)
		{
			glUniformMatrix4fv(objectTransformLocation, 1, GL_TRUE,
				&transform.e[0][0]);
		}
		void setViewTransform(const math::Mat44 &transform)
		{
			glUniformMatrix4fv(viewTransformLocation, 1, GL_TRUE,
				&transform.e[0][0]);
		}
		void setProjectionTransform(const math::Mat44 &transform)
		{
			glUniformMatrix4fv(projectionTransformLocation, 1, GL_TRUE,
				&transform.e[0][0]);
		}
		void setCamera(Camera *camera)
		{
			currentCamera = camera;
		}
		void unsetCamera()
		{
			currentCamera = 0;
		}
		void enableAlphaBlending()
		{
			glEnable(GL_BLEND);
			glBlendEquationSeparate(GL_FUNC_ADD, GL_FUNC_ADD);
			glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ZERO);
		}
		void enableAdditiveBlending()
		{
			glEnable(GL_BLEND);
			glBlendEquationSeparate(GL_FUNC_ADD, GL_FUNC_ADD);
			glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE, GL_ONE, GL_ONE);
		}
		void disableBlending()
		{
			glDisable(GL_BLEND);
		}
		/* --------------------------------------------------------------------------- */
		void __setVertexFormat()
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
		void __unsetVertexFormat()
		{
			glDisableVertexAttribArray(0);
			glDisableVertexAttribArray(1);
			glDisableVertexAttribArray(2);
		}
		/* --------------------------------------------------------------------------- */
		namespace __core
		{
			Int32 init()
			{
				Int32 result = setInitialRenderStates();
				if (result != 0)
				{
					return 1;
				}
				result = initDefaultShaders();
				if (result != 0)
				{
					return 1;
				}
				result = initDefaultShadersUniformVariables();
				if (result != 0)
				{
					return 1;
				}
				return 0;
			}
			void beginRender()
			{
				glUseProgram(shaderProgram);
				updateDefaultShadersUniformVariables();
			}
			void endRender()
			{
			}
			void onEnd()
			{
			}
		}
	}
}
/* ----------------------------------------------------------------------------------- */
namespace
{
	blitz::Int32 createShader(Shader *out_shader, const char *source,
		blitz::Uint32 glShaderType)
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
	blitz::Int32 createShaderProgram(ShaderProgram *out_shaderProgram,
		Shader *shaderList, blitz::Int32 shaderCount)
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
	blitz::Int32 getShaderUniformVariableLocation(const char *identifier)
	{
		return glGetUniformLocation(shaderProgram, identifier);
	}
	/* ------------------------------------------------------------------------------- */
	blitz::Int32 setInitialRenderStates()
	{
		GLenum result = glewInit();
		if (result != GLEW_OK)
		{
			return 1;
		}
		glGenBuffers(1, &vertexBuffer);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
		glGenBuffers(1, &indexBuffer);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_GEQUAL);
		glClearDepthf(-1.0f);
		return 0;
	}
	blitz::Int32 initDefaultShaders()
	{
		Shader shaderList[2];
		blitz::Int32 result = createShader(&shaderList[0], DEFAULT_VERTEX_SHADER_SOURCE,
			GL_VERTEX_SHADER);
		if (result != 0)
		{
			return 1;
		}
		result = createShader(&shaderList[1], DEFAULT_FRAGMENT_SHADER_SOURCE,
			GL_FRAGMENT_SHADER);
		if (result != 0)
		{
			return 1;
		}
		result = createShaderProgram(&shaderProgram, shaderList, 2);
		if (result != 0)
		{
			return 1;
		}
		glUseProgram(shaderProgram);
		return 0;
	}
	blitz::Int32 initDefaultShadersUniformVariables()
	{
		objectTransformLocation = getShaderUniformVariableLocation("objectTransform");
		viewTransformLocation =
			getShaderUniformVariableLocation("viewTransform");
		projectionTransformLocation =
			getShaderUniformVariableLocation("projectionTransform");
		textureSamplerLocation = getShaderUniformVariableLocation("textureSampler");
		glUniform1i(textureSamplerLocation, 0);
		useTextureLocation = getShaderUniformVariableLocation("useTexture");
		glUniform1i(useTextureLocation, 0);
		blitz::math::Mat44 identityMatrix;
		blitz::math::buildIdentity(&identityMatrix);
		glUniformMatrix4fv(objectTransformLocation, 1, GL_TRUE, &identityMatrix.e[0][0]);
		glUniformMatrix4fv(viewTransformLocation, 1, GL_TRUE,
			&identityMatrix.e[0][0]);
		glUniformMatrix4fv(projectionTransformLocation, 1, GL_TRUE,
			&identityMatrix.e[0][0]);
		return 0;
	}
	void updateDefaultShadersUniformVariables()
	{
		if (currentCamera)
		{
			blitz::graphics::setViewTransform(currentCamera->getView());
			blitz::graphics::setProjectionTransform(currentCamera->getProjection());
		}
	}
}