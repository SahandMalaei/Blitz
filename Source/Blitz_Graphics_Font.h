#ifndef BLITZ_GRAPHICS_FONT_H
#define BLITZ_GRAPHICS_FONT_H

#include "Blitz_BaseTypes.h"

namespace blitz
{
	namespace graphics
	{
		typedef Int32 Texture;

		class Font
		{
		public:
			Font();
			Font(const Font &font);
			Font & operator =(const Font &font);
		private:
			Int32 *height_, *widthList_, *heightList_, *horizontalOffsetList_,
			 *verticalOffsetList_, *horizontalAdvanceList_;
			Texture *textureList_;
		};
	}
}

#endif