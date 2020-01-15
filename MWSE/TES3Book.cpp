#include "TES3Book.h"

#include "TES3Util.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "LuaBookGetTextEvent.h"

#include "Log.h"

#include <cstring>

constexpr auto TES3_Book_loadBookText = 0x4A2A90;

namespace TES3
{

const auto TES3_Book_loadBookText_fn = reinterpret_cast< char *( __thiscall * )( Book * ) >( TES3_Book_loadBookText );
const auto TES3_Book_Text_Buffer_ptr = reinterpret_cast< char ** >( 0x7CA44C );

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

	// Create our new buffer.
	auto length = strlen( newText.value() ) + 1;
	char *buffer = reinterpret_cast< char * >( mwse::tes3::_new( length ) );

	// Delete the previous buffer and replace it with this one.
	mwse::tes3::_delete( *TES3_Book_Text_Buffer_ptr );
	*TES3_Book_Text_Buffer_ptr = buffer;

	// Copy into the buffer and get out of here.
	std::snprintf( buffer, length, newText.value() );

	return buffer;
}

}

