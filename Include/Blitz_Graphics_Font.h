#ifndef BLITZ_GRAPHICS_FONT_H
#define BLITZ_GRAPHICS_FONT_H

#include <string>

#include "Blitz_BaseTypes.h"
#include "Blitz_Graphics.h"

namespace blitz
{
	namespace graphics
	{
		typedef Uint32 Texture;

		class Font
		{
		public:
			Font();
			Font(const Font &font);
			Font & operator =(const Font &font);

			Texture getTexture(Int32 characterIndex);
		private:
			Int32 height_;
			Int32 *widthList_, *heightList_, *horizontalOffsetList_,
			 *verticalOffsetList_, *horizontalAdvanceList_;
			Texture *textureList_;

			friend Int32 loadFont(Font *out_font, const char *fileAddress,
				Int32 characterHeight);
			friend void unloadFont(Font *out_font);
			friend void print(const std::string &text, const Font &font,
				math::Vec2 position, float depth, ColorRgba color, float characterHeight,
				float spacing);
		};

		Int32 loadFont(Font *out_font, const char *fileAddress, Int32 characterHeight);
		void unloadFont(Font *out_font);

		void print(const std::string &text, const Font &font, math::Vec2 position,
			float depth, ColorRgba color, float characterHeight, float spacing);
	}
}

#endif