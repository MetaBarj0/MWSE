#pragma once

#include <unordered_map>
#include <string>
#include <utility>

namespace mwse::tes3
{

class BookTextStore
{
public:
	static BookTextStore &getInstance();

public:
	std::string &operator[]( const std::string &key );
	bool hasTextForBookId( const std::string &key );
	void clearText( const std::string &key );

private:
	BookTextStore() = default;
	~BookTextStore() = default;
	BookTextStore( const BookTextStore & ) = default;
	BookTextStore( BookTextStore && ) = default;

	BookTextStore &operator=( const BookTextStore & ) = default;
	BookTextStore &operator=( BookTextStore && ) = default;

private:
	std::unordered_map< std::string, std::string > textStore_;
};

}
