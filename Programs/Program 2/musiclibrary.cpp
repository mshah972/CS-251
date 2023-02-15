/// TODO Update File Header
///
/// Assignment details and provided code are created and
/// owned by Adam T Koehler, PhD - Copyright 2023.
/// University of Illinois Chicago - CS 251 Spring 2023

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <map>
#include <set>
#include <cctype>
using namespace std;

// INSERTS GIVEN HELPERS CODE BELOW - DO NOT REMOVE
#include "helpers.cpp"
// INSERTS GIVEN HELPERS CODE ABOVE - DO NOT REMOVE

//
// NOTE TO STUDENTS:
// You may use the functions in the helpers file,
// but you may not modify the file or its contents in any way whatsoever.
//

//
// STUDENT CODE MAY GO BELOW THIS LINE
//

// Global Export and Impoert File Names
string userExportFile = "musicdatabase.txt";
string userImportFile = "musicdatabase.txt";

// Struct to hold the songs and artists
struct Song
{
	set<string> songs;
	set<string> artists;
};

// Map to hold the albums
map<string, Song> AlbumMap;

// Clear Function to clear the map
void clearCommand()
{
	AlbumMap.clear();
}

// Load Function to load the file
void loadCommand(string filename)
{
	if (filename.empty())
	{
		filename = userImportFile;
	}
	else
	{
		userImportFile = filename;
	}

	ifstream inFile(filename);

	if (!inFile)
	{
		cout << "Error: Could not open music library file - nofilehere.txt" << endl;
		return;
	}

	string album, line, artist;

	bool first = false;
	while (!inFile.eof())
	{
		bool second = false;

		if (first != true)
		{
			getline(inFile, album);
			first = true;
			continue;
		}

		getline(inFile, line);

		for (char c : line)
		{
			if (isdigit(c))
			{
				second = true;
				break;
			}
		}

		if (second != true && line != album)
		{
			artist = line;
			AlbumMap[album].artists.insert(line);
		}
		else if (second == true && line != album)
		{
			AlbumMap[album].songs.insert(line);
		}
		else
		{
			first = false;
		}
	}
	inFile.close();

	for (auto &album : AlbumMap)
	{
		for (auto &artist : album.second.artists)
		{
			for (auto &song : album.second.songs)
			{
				if (artist == song)
				{
					album.second.songs.erase(song);
				}
			}
		}
	}
}

// Stats Function to print out the stats
void statsCommand(string userInput)
{
	int numAlbums = 0;
	int numArtists = 0;
	int numSongs = 0;

	set<string> countedArtists;

	numAlbums = AlbumMap.size();

	for (auto &album : AlbumMap)
	{
		for (auto &artist : album.second.artists)
		{
			if (countedArtists.find(artist) == countedArtists.end())
			{
				countedArtists.insert(artist);
			}
		}
	}

	numArtists = countedArtists.size();

	// count the number of songs
	for (auto &album : AlbumMap)
	{
		numSongs += album.second.songs.size();
	}

	cout << "Overall Music Library Stats" << endl;
	cout << "===========================" << endl;
	cout << "Total Records: " << numAlbums << endl;
	cout << "Total Unique Artists: " << numArtists << endl;
	cout << "Total Songs: " << numSongs << endl;
	cout << endl;

	if (userInput == "-d")
	{

		cout << "Your Current Music Library Includes" << endl;
		cout << "===================================" << endl;

		for (auto &album : AlbumMap)
		{
			cout << album.first << endl;
			for (auto &artist : album.second.artists)
			{
				cout << " " << artist << endl;
			}
			for (auto &song : album.second.songs)
			{
				cout << "   " << song << endl;
			}
		}

		cout << endl;
	}
}

// Export Function to export the file
void exportCommand(string filename)
{
	if (filename.empty())
	{
		filename = userExportFile;
	}
	else
	{
		userExportFile = filename;
	}

	ofstream outFile(filename);

	if (!outFile)
	{
		cout << "Error: Unable to write the file" << endl;
		return;
	}

	for (auto &album : AlbumMap)
	{
		outFile << album.first << endl;
		for (auto &artist : album.second.artists)
		{
			outFile << artist << endl;
		}

		for (auto &song : album.second.songs)
		{
			outFile << song << endl;
		}

		outFile << album.first << endl;
	}
	outFile.close();
}

// Search Function to search the file for the given input
void searchCommand(string userInput)
{

	string searchType = "";
	string searchValue = "";

	splitFirstWord(userInput, searchType, searchValue);

	if ((searchType != "artist") && (searchType != "album") && (searchType != "song"))
	{
		cout << "Error: Search terms cannot be empty." << endl;
		cout << "No results found.\n"
			 << endl;
		return;
	}

	if ((searchValue.empty()) || (searchValue == " "))
	{
		cout << "Error: Search terms cannot be empty." << endl;
		cout << "No results found.\n"
			 << endl;
		return;
	}

	if (searchType == "artist")
	{
		set<string> albums;
		for (auto &album : AlbumMap)
		{
			for (auto &artist : album.second.artists)
			{
				string artistLower = artist;
				string searchValueLower = searchValue;

				// convert to lowercase
				for (char &c : artistLower)
				{
					c = tolower(c);
				}

				for (char &c : searchValueLower)
				{
					c = tolower(c);
				}

				// search for the search value in the artist
				if (artistLower.find(searchValueLower) != string::npos)
				{
					albums.insert(album.first);
				}
			}
		}
		if (albums.empty())
		{
			cout << "No results found." << endl;
		}
		else
		{
			cout << "Your search results exist in the following albums: " << endl;
			for (auto &album : albums)
			{
				cout << album << endl;
			}
			cout << endl;
		}
	}
	else if (searchType == "album")
	{
		if (searchValue.empty())
		{
			cout << "Error: Search terms cannot be empty." << endl;
			return;
		}
		set<string> albums;
		for (auto &album : AlbumMap)
		{
			string albumLower = album.first;
			string searchValueLower = searchValue;
			
			for (char &c : albumLower)
			{
				c = tolower(c);
			}

			for (char &c : searchValueLower)
			{
				c = tolower(c);
			}

			if (albumLower.find(searchValueLower) != string::npos)
			{
				albums.insert(album.first);
			}
		}
		if (albums.empty())
		{
			cout << "No results found." << endl;
		}
		else
		{
			cout << "Your search results exist in the following albums: " << endl;
			for (auto &album : albums)
			{
				cout << album << endl;
			}
			cout << endl;
		}
	}
	else if (searchType == "song")
	{
		set<string> albums;
		for (auto &album : AlbumMap)
		{
			for (auto &song : album.second.songs)
			{
				string songLower = song;
				string searchValueLower = searchValue;
		
				for (char &c : songLower)
				{
					c = tolower(c);
				}
				
				for (char &c : searchValueLower)
				{
					c = tolower(c);
				}

				if (songLower.find(searchValueLower) != string::npos)
				{
					albums.insert(album.first);
				}
			}
		}
		if (albums.empty())
		{
			cout << "No results found." << endl;
		}
		else
		{
			cout << "Your search results exist in the following albums: " << endl;
			for (auto &album : albums)
			{
				cout << album << endl;
			}
			cout << endl;
		}
	}
	else
	{
		cout << "Error: Invalid search type." << endl;
	}

}

int main()
{
	string userEntry;
	string command, remains;

	// TODO: Declare any necessary variables for the music libary

	// Display welcome message once per program execution
	cout << "Welcome to the Music Library App" << endl;
	cout << "--------------------------------" << endl;

	// Stay in menu until exit command
	do
	{
		cout << endl;
		cout << "Enter a command (help for help): " << endl;
		getline(cin, userEntry);
		cout << endl;

		// Split the user entry into two pieces
		splitFirstWord(userEntry, command, remains);
		tolower(command);

		// take an action, one per iteration, based on the command
		if (command == "help")
		{
			helpCommand();
		}
		else if (command == "clear")
		{
			clearCommand();
		}
		else if (command == "export")
		{
			exportCommand(remains);
		}
		else if (command == "load")
		{
			loadCommand(remains);
		}
		else if (command == "stats")
		{
			statsCommand(remains);
		}
		else if (command == "search")
		{
			searchCommand(remains);
		}

	} while (command != "exit");

	cout << "Thank you for using the Music Library App" << endl;
	return 0;
}
