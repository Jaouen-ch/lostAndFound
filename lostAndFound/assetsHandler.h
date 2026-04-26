#pragma once

#include "utils.h"

class assetsHandler
{
public:
    enum class texturesIndices
    {
        defaultTexture,
        textBackground,
        button
    };

    enum class fontsIndices
    {
        righteous
    };

    enum class musicsIndices
    {
        //musics
    };

    enum class soundsIndices
    {
        //sounds
    };

private:
    static assetsHandler* engineAssetsHandler;

    std::vector<sf::Texture*> tabTextures;
    std::vector<sf::Font*> tabFonts;
    std::vector<sf::Music*> tabMusics;
    std::vector<sf::Sound*> tabSounds;

    assetsHandler();

public:
    ~assetsHandler();

    sf::Texture& getTexture(texturesIndices index);
    sf::Font& getFont(fontsIndices index);
    sf::Music& getMusic(musicsIndices index);
    sf::Sound& getSound(soundsIndices index);

    void loadAllTextures();
    void loadAllFonts();
    void loadAllMusics();
	void loadAllSounds();
    void loadTexture(texturesIndices _index, const char* filename);
    void loadFont(fontsIndices _index, const char* filename);
    void loadMusic(musicsIndices _index, const char* filename);
    void loadSound(soundsIndices _index, const char* filename);

    static assetsHandler* getAssets();
};