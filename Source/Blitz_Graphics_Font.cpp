#include "Blitz_Graphics_Font.h"
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
	}
}