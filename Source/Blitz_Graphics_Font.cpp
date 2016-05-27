#include "../Include/Blitz_Graphics_Font.h"
/* ------------------------------------------------------------------------------------ */
#include "ft2build.h"
#include FT_FREETYPE_H
#include "GL/glew.h"
/* ------------------------------------------------------------------------------------ */
#include "Blitz_Debug.h"
#include "../Include/Blitz_BaseTypes.h"
/* ------------------------------------------------------------------------------------ */
namespace
{
	const blitz::Int32 CHARACTER_COUNT = 128;
	/* -------------------------------------------------------------------------------- */
	blitz::Bool freeTypeInitialized = 0;
	FT_Library freeTypeLibrary;
	/* -------------------------------------------------------------------------------- */
	blitz::Int32 initializeFreeType();
}
/* ------------------------------------------------------------------------------------ */
namespace blitz
{
	namespace graphics
	{
		Font::Font() :
			height_(0),
			widthList_(0),
			heightList_(0),
			horizontalOffsetList_(0),
			verticalOffsetList_(0),
			horizontalAdvanceList_(0),
			textureList_(0)
		{
		}
		Font::Font(const Font &font) :
			height_(font.height_),
			widthList_(font.widthList_),
			heightList_(font.heightList_),
			horizontalOffsetList_(font.horizontalOffsetList_),
			verticalOffsetList_(font.verticalOffsetList_),
			horizontalAdvanceList_(font.horizontalAdvanceList_),
			textureList_(font.textureList_)
		{
		}
		Font & Font::operator =(const Font &font)
		{
			height_ = font.height_;
			widthList_ = font.widthList_;
			heightList_ = font.heightList_;
			horizontalOffsetList_ = font.horizontalOffsetList_;
			verticalOffsetList_ = font.verticalOffsetList_;
			horizontalAdvanceList_ = font.horizontalAdvanceList_;
			textureList_ = font.textureList_;
			return *this;
		}
		Texture Font::getTexture(Int32 characterIndex)
		{
			__BLITZ_ASSERT(textureList_);
			__BLITZ_ASSERT(characterIndex >= 0);
			__BLITZ_ASSERT(characterIndex < CHARACTER_COUNT);
			return textureList_[characterIndex];
		}
		/* ---------------------------------------------------------------------------- */
		Int32 loadFont(Font *out_font, const char *fileAddress, Int32 characterHeight)
		{
			__BLITZ_ASSERT(out_font);
			__BLITZ_ASSERT(fileAddress);
			__BLITZ_ASSERT(characterHeight > 0);
			Int32 result = 0;
			if (!freeTypeInitialized)
			{
				result = initializeFreeType();
				if (result != 0)
				{
					return 1;
				}
			}
			FT_Face fontFace;
			result = FT_New_Face(freeTypeLibrary, fileAddress, 0, &fontFace);
			if (result != 0)
			{
				__BLITZ_THROW_ERROR("Failed to load font face.");
				return 1;
			}
			result = FT_Set_Pixel_Sizes(fontFace, 0, characterHeight);
			if (result != 0)
			{
				__BLITZ_THROW_ERROR("Failed to set font pixel size.");
				return 1;
			}
			out_font->height_ = characterHeight;
			out_font->widthList_ = new Int32[CHARACTER_COUNT];
			out_font->heightList_ = new Int32[CHARACTER_COUNT];
			out_font->horizontalOffsetList_ = new Int32[CHARACTER_COUNT];
			out_font->verticalOffsetList_ = new Int32[CHARACTER_COUNT];
			out_font->horizontalAdvanceList_ = new Int32[CHARACTER_COUNT];
			out_font->textureList_ = new Texture[CHARACTER_COUNT];
			for (Int32 i = 0; i < CHARACTER_COUNT; ++i)
			{
				result = FT_Load_Char(fontFace, i, FT_LOAD_RENDER);
				if (result != 0)
				{
					__BLITZ_THROW_ERROR("Failed to load glyph " + std::to_string(i) +
						".");
					return 1;
				}
				Int32 width = fontFace->glyph->bitmap.width,
					height = fontFace->glyph->bitmap.rows;
				out_font->widthList_[i] = width;
				out_font->heightList_[i] = height;
				out_font->horizontalOffsetList_[i] = fontFace->glyph->bitmap_left;
				out_font->verticalOffsetList_[i] = fontFace->glyph->bitmap_top;
				out_font->horizontalAdvanceList_[i] = fontFace->glyph->advance.x >> 6;
				Uint8 *imageData = new Uint8[height * width * 4];
				for (Int32 i = 0; i < height; ++i)
				{
					for (Int32 j = 0; j < width; ++j)
					{
						imageData[i * width * 4 + j * 4] = 255;
						imageData[i * width * 4 + j * 4 + 1] = 255;
						imageData[i * width * 4 + j * 4 + 2] = 255;
						imageData[i * width * 4 + j * 4 + 3] =
							fontFace->glyph->bitmap.buffer[i * width + j];
					}
				}
				glGenTextures(1, &out_font->textureList_[i]);
				glBindTexture(GL_TEXTURE_2D, out_font->textureList_[i]);
				GLint imageFormat = GL_BGRA;
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0,
					imageFormat, GL_UNSIGNED_BYTE, imageData);
				result = glGetError();
				if (result != 0)
				{
					__BLITZ_THROW_ERROR("Failed to create font texture " +
						std::to_string(i) + ".");
					return 1;
				}
				glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
				glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
				glBindTexture(GL_TEXTURE_2D, 0);
				delete[] imageData;
			}
			FT_Done_Face(fontFace);
			blitz::__debug::throwMessage("Font \"" + std::string(fileAddress) +
				"\" loaded with height " + std::to_string(characterHeight) + ".");
			return 0;
		}
		void unloadFont(Font *out_font)
		{
			__BLITZ_ASSERT(out_font);
			__BLITZ_ASSERT(out_font->textureList_);
			for (Int32 i = 0; i < CHARACTER_COUNT; ++i)
			{
				glDeleteTextures(1, &out_font->textureList_[i]);
			}
			delete[] out_font->textureList_;
			out_font->textureList_ = 0;
			out_font->height_ = 0;
			delete[] out_font->widthList_;
			out_font->widthList_ = 0;
			delete[] out_font->heightList_;
			out_font->heightList_ = 0;
			delete[] out_font->horizontalOffsetList_;
			out_font->horizontalOffsetList_ = 0;
			delete[] out_font->verticalOffsetList_;
			out_font->verticalOffsetList_ = 0;
			delete[] out_font->horizontalAdvanceList_;
			out_font->horizontalAdvanceList_ = 0;
		}
		void print(const std::string &text, const Font &font, math::Vec2 position,
			float depth, ColorRgba color, float characterHeight, float spacing)
		{
			__BLITZ_ASSERT(font.textureList_);
			Uint32 textLength = text.length();
			float offset = 0.0f;
			float scale = (float)characterHeight / (float)font.height_;
			for (Int32 i = 0; i < (Int32)textLength; ++i)
			{
				if ((Int32)text[i] >= CHARACTER_COUNT)
				{
					continue;
				}
				blitz::graphics::setTexture(font.textureList_[(Int32)text[i]]);
				math::Vec2 topLeft = position + blitz::math::Vec2(offset +
					font.horizontalOffsetList_[text[i]] * scale,
					characterHeight - font.verticalOffsetList_[text[i]] * scale);
				math::Vec2 dimensions =
					blitz::math::Vec2(font.widthList_[text[i]] * scale,
					font.heightList_[text[i]] * scale);
				Vertex vertexList[4];
				vertexList[0] = Vertex(math::Vec3(topLeft.x, topLeft.y, depth), color,
					math::Vec2(0.0f, 0.0f));
				vertexList[1] = Vertex(
					math::Vec3(topLeft.x + dimensions.x, topLeft.y, depth),
					color, math::Vec2(1.0f, 0.0f));
				vertexList[2] = Vertex(
					math::Vec3(topLeft.x + dimensions.x, topLeft.y + dimensions.y, depth),
					color, math::Vec2(1.0f, 1.0f));
				vertexList[3] = Vertex(
					math::Vec3(topLeft.x, topLeft.y + dimensions.y, depth),
					color, math::Vec2(0.0f, 1.0f));
				Uint32 indexList[6] = {0, 1, 2, 0, 2, 3};
				draw(vertexList, 4, indexList, 6);
				offset += font.horizontalAdvanceList_[text[i]] * scale + (float)spacing;
			}
			blitz::graphics::unsetTexture();
		}
	}
}
/* ------------------------------------------------------------------------------------ */
namespace
{
	blitz::Int32 initializeFreeType()
	{
		blitz::Int32 result = FT_Init_FreeType(&freeTypeLibrary);
		if (result != 0)
		{
			__BLITZ_THROW_ERROR("Failed to initialize FreeType.");
			return 1;
		}
		blitz::__debug::throwMessage("FreeType initialized.");
		freeTypeInitialized = 1;
		return 0;
	}
}