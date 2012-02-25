// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef	MOAIFREETYPEFONTREADER_H
#define	MOAIFREETYPEFONTREADER_H

#if USE_FREETYPE

#include <contrib/utf8.h>
#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_STROKER_H

#include <moaicore/MOAIFontReader.h>

//================================================================//
// MOAIFreeTypeFontReader
//================================================================//
class MOAIFreeTypeFontReader :
	public MOAIFontReader {
private:

	FT_Library		mLibrary;
	FT_Face			mFace;
	float			mFaceHeight;

public:
	
	DECL_LUA_FACTORY ( MOAIFreeTypeFontReader )

	//----------------------------------------------------------------//
	void			CloseFont					();
	void			GetFaceMetrics				( MOAIGlyphSet& glyphDeck );
	bool			GetKernVec					( MOAIGlyph& glyph0, MOAIGlyph& glyph1, MOAIKernVec& kernVec );
	bool			HasKerning					();
					MOAIFreeTypeFontReader		();
					~MOAIFreeTypeFontReader		();
	void			OpenFont					( MOAIFont& font );
	void			RegisterLuaClass			( MOAILuaState& state );
	void			RegisterLuaFuncs			( MOAILuaState& state );
	void			RenderGlyph					( MOAIFont& font, MOAIGlyph& glyph );
	void			SerializeIn					( MOAILuaState& state, MOAIDeserializer& serializer );
	void			SerializeOut				( MOAILuaState& state, MOAISerializer& serializer );
	void			SetFaceSize					( float size );
};

#endif
#endif