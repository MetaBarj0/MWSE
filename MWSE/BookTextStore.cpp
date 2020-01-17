#include "BookTextStore.h"

namespace mwse::tes3
{
BookTextStore &BookTextStore::getInstance()
{
	static BookTextStore store;

	return store;
}

std::string &BookTextStore::operator[]( const std::string &key )
{
	return textStore_[ key ];
}

bool BookTextStore::hasTextForBookId( const std::string &key )
{
	return textStore_.count( key ) > 0;
}

void BookTextStore::clearText( const std::string &key )
{
	textStore_.erase( key );
}

}