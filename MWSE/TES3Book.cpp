#include "TES3Book.h"

#include "TES3Util.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "LuaBookGetTextEvent.h"

#include "Log.h"

#include <cstring>

namespace TES3
{

static const auto TES3_Book_ctor = reinterpret_cast< void( __thiscall * ) ( Book * ) >( 0x4A1E90 );
Book::Book() :
	stolenList{},
	name{},
	script{},
	model{},
	icon{},
	weight{},
	value{},
	bookType{},
	skillToRaise{},
	enchantCapacity{},
	enchantment{},
	unknown_0x6C{}
{
	TES3_Book_ctor( this );
}

static const auto TES3_Book_dtor = reinterpret_cast< void( __thiscall * ) ( Book * ) >( 0x4A1F70 );
Book::~Book()
{
	TES3_Book_dtor( this );
}

static const auto TES3_Book_Text_Buffer_ptr = reinterpret_cast< char ** >( 0x7CA44C );
static const char *changeBookText( const char *text )
{
	// Create our new buffer.
	auto length = strlen( text ) + 1;
	char *buffer = reinterpret_cast< char * >( mwse::tes3::_new( length ) );

	// Delete the previous buffer and replace it with this one.
	mwse::tes3::_delete( *TES3_Book_Text_Buffer_ptr );
	*TES3_Book_Text_Buffer_ptr = buffer;

	// Copy into the buffer and get out of here.
	std::snprintf( buffer, length, text );

	return buffer;
}

static const auto TES3_Book_loadBookText_fn = reinterpret_cast< char *( __thiscall * )( Book * ) >( 0x4A2A90 );
const char *Book::getBookText()
{
	if( !mwse::lua::event::BookGetTextEvent::getEventEnabled() )
		return TES3_Book_loadBookText_fn( this );

	auto stateHandle = mwse::lua::LuaManager::getInstance().getThreadSafeStateHandle();
	sol::object eventResult = stateHandle.triggerEvent( new mwse::lua::event::BookGetTextEvent( this ) );

	if( !eventResult.valid() )
		return TES3_Book_loadBookText_fn( this );

	sol::table eventData = eventResult;
	sol::optional< const char * > newText = eventData[ "text" ];
	if( !newText )
		return TES3_Book_loadBookText_fn( this );

	return changeBookText( newText.value() );
}

void Book::setBookText( std::string_view text )
{
}

}

