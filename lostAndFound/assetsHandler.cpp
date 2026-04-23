#include "assetsHandler.h"

assetsHandler* assetsHandler::engineAssetsHandler = nullptr;

assetsHandler::assetsHandler()
{
    loadAllTextures();
    loadAllFonts();
    loadAllMusics();
	loadAllSounds();
}

assetsHandler::~assetsHandler()
{
    delete engineAssetsHandler;
    engineAssetsHandler = nullptr;

    for (auto texture : tabTextures)
    {
        delete texture;
        texture = nullptr;
    }
    for (auto font : tabFonts)
    {
        delete font;
        font = nullptr;
    }
    for (auto music : tabMusics)
    {
        delete music;
        music = nullptr;
    }
    for (auto sound : tabSounds)
    {
        delete sound;
        sound = nullptr;
    }
}

void assetsHandler::loadAllTextures()
{
    loadTexture(texturesIndices::defaultTexture, "assets/defaultTexture.png");
}

void assetsHandler::loadAllFonts()
{
    //fonts
}

void assetsHandler::loadAllMusics()
{
    //musics
}

void assetsHandler::loadAllSounds()
{
	//sounds
}

void assetsHandler::loadTexture(texturesIndices _index, const char* fileName)
{
    auto* texture = new sf::Texture(fileName);

    auto index = (int)_index;
    if (index >= tabTextures.size())
    {
        tabTextures.resize(index + 1);
    }

    tabTextures[index] = texture;
}

void assetsHandler::loadFont(fontsIndices _index, const char* fileName)
{
    auto* font = new sf::Font(fileName);

    auto index = (int)_index;
    if (index >= tabFonts.size())
    {
        tabFonts.resize(index + 1);
    }

    tabFonts[index] = font;
}

void assetsHandler::loadMusic(musicsIndices _index, const char* fileName)
{
    auto* music = new sf::Music(fileName);

    auto index = (int)_index;
    if (index >= tabMusics.size())
    {
        tabMusics.resize(index + 1);
    }

    tabMusics[index] = music;
}

void assetsHandler::loadSound(soundsIndices _index, const char* fileName)
{
    sf::SoundBuffer buffer(fileName);
    auto* sound = new sf::Sound(buffer);

    auto index = (int)_index;
    if (index >= tabSounds.size())
    {
        tabSounds.resize(index + 1);
    }

    tabSounds[index] = sound;
}

sf::Texture& assetsHandler::getTexture(texturesIndices index)
{
    return *tabTextures[(int)index];
}

sf::Font& assetsHandler::getFont(fontsIndices index)
{
    return *tabFonts[(int)index];
}

sf::Music& assetsHandler::getMusic(musicsIndices index)
{
	return *tabMusics[(int)index];
}

sf::Sound& assetsHandler::getSound(soundsIndices index)
{
    return *tabSounds[(int)index];
}

assetsHandler* assetsHandler::getAssets()
{
    if (engineAssetsHandler == nullptr)
    {
        engineAssetsHandler = new assetsHandler();
    }
    return engineAssetsHandler;
}