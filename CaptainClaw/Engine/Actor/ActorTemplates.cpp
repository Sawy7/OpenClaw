#include "ActorTemplates.h"
#include "../GameApp/BaseGameApp.h"
#include "../GameApp/BaseGameLogic.h"
#include "../Events/EventMgr.h"
#include "../Events/Events.h"

#include <time.h>

namespace ActorTemplates
{

    // The empty image set strings signal that these pickups cant be used like this. Maybe change ?
    std::map<PickupType, std::string> g_PickupTypeToImageSetMap =
    {
        { PickupType_Default,                   "GAME_TREASURE_COINS" },
        { PickupType_Treasure_Goldbars,         "GAME_TREASURE_GOLDBARS" },
        { PickupType_Treasure_Rings_Red,        "GAME_TREASURE_RINGS_RED" },
        { PickupType_Treasure_Rings_Green,      "GAME_TREASURE_RINGS_GREEN" },
        { PickupType_Treasure_Rings_Blue,       "GAME_TREASURE_RINGS_BLUE" },
        { PickupType_Treasure_Rings_Purple,     "GAME_TREASURE_RINGS_PURPLE" },
        { PickupType_Treasure_Necklace,         "GAME_TREASURE_NECKLACE" },
        { PickupType_Treasure_Crosses_Red,      "GAME_TREASURE_CROSSES_RED" },
        { PickupType_Treasure_Crosses_Green,    "GAME_TREASURE_CROSSES_GREEN" },
        { PickupType_Treasure_Crosses_Blue,     "GAME_TREASURE_CROSSES_BLUE" },
        { PickupType_Treasure_Crosses_Purple,   "GAME_TREASURE_CROSSES_PURPLE" },
        { PickupType_Treasure_Scepters_Red,     "GAME_TREASURE_SCEPTERS_RED" },
        { PickupType_Treasure_Scepters_Green,   "GAME_TREASURE_SCEPTERS_GREEN" },
        { PickupType_Treasure_Scepters_Blue,    "GAME_TREASURE_SCEPTERS_BLUE" },
        { PickupType_Treasure_Scepters_Purple,  "GAME_TREASURE_SCEPTERS_PURPLE" },
        { PickupType_Treasure_Geckos_Red,       "GAME_TREASURE_GECKOS_RED" },
        { PickupType_Treasure_Geckos_Green,     "GAME_TREASURE_GECKOS_GREEN" },
        { PickupType_Treasure_Geckos_Blue,      "GAME_TREASURE_GECKOS_BLUE" },
        { PickupType_Treasure_Geckos_Purple,    "GAME_TREASURE_GECKOS_PURPLE" },
        { PickupType_Ammo_Deathbag,             "GAME_AMMO_DEATHBAG" },
        { PickupType_Ammo_Shot,                 "GAME_AMMO_SHOT" },
        { PickupType_Ammo_Shotbag,              "GAME_AMMO_SHOTBAG" },
        { PickupType_Powerup_Catnip_1,          "GAME_CATNIPS_NIP1" },
        { PickupType_Powerup_Catnip_2,          "GAME_CATNIPS_NIP2" },
        { PickupType_Health_Breadwater,         "GAME_HEALTH_BREADWATER" },
        { PickupType_Health_25,                 "GAME_HEALTH_POTION3" },
        { PickupType_Health_10,                 "GAME_HEALTH_POTION1" },
        { PickupType_Health_15,                 "GAME_HEALTH_POTION2" },
        { PickupType_Ammo_Magic_5,              "GAME_MAGIC_GLOW" },
        { PickupType_Ammo_Magic_10,             "GAME_MAGIC_STARGLOW" },
        { PickupType_Ammo_Magic_25,             "GAME_MAGIC_MAGICCLAW" },
        { PickupType_Mappiece,                  "GAME_MAPPIECE" },
        { PickupType_Warp,                      "GAME_WARP" },
        { PickupType_Treasure_Coins,            "GAME_TREASURE_COINS" },
        { PickupType_Ammo_Dynamite,             "GAME_DYNAMITE" },
        { PickupType_Curse_Ammo,                "" },
        { PickupType_Curse_Magic,               "" },
        { PickupType_Curse_Health,              "" },
        { PickupType_Curse_Death,               "" },
        { PickupType_Curse_Treasure,            "" },
        { PickupType_Curse_Freeze,              "" },
        { PickupType_Treasure_Chalices_Red,     "GAME_TREASURE_CHALICES_RED" },
        { PickupType_Treasure_Chalices_Green,   "GAME_TREASURE_CHALICES_GREEN" },
        { PickupType_Treasure_Chalices_Blue,    "GAME_TREASURE_CHALICES_BLUE" },
        { PickupType_Treasure_Chalices_Purple,  "GAME_TREASURE_CHALICES_PURPLE" },
        { PickupType_Treasure_Crowns_Red,       "GAME_TREASURE_CROWNS_RED" },
        { PickupType_Treasure_Crowns_Green,     "GAME_TREASURE_CROWNS_GREEN" },
        { PickupType_Treasure_Crowns_Blue,      "GAME_TREASURE_CROWNS_BLUE" },
        { PickupType_Treasure_Crowns_Purple,    "GAME_TREASURE_CROWNS_PURPLE" },
        { PickupType_Treasure_Skull_Red,        "GAME_TREASURE_JEWELEDSKULL_RED" },
        { PickupType_Treasure_Skull_Green,      "GAME_TREASURE_JEWELEDSKULL_GREEN" },
        { PickupType_Treasure_Skull_Blue,       "GAME_TREASURE_JEWELEDSKULL_BLUE" },
        { PickupType_Treasure_Skull_Purple,     "GAME_TREASURE_JEWELEDSKULL_PURPLE" },
        { PickupType_Powerup_Invisibility,      "" },
        { PickupType_Powerup_Invincibility,     "" },
        { PickupType_Powerup_Life,              "" },
        { PickupType_Powerup_FireSword,         "" },
        { PickupType_Powerup_LightningSword,    "" },
        { PickupType_Powerup_IceSword,          "" },
    };

    std::map<PickupType, std::string> g_PickupTypeToPickupSoundMap =
    {
        { PickupType_Default,                   SOUND_GAME_TREASURE_COIN },
        { PickupType_Treasure_Goldbars,         SOUND_GAME_TREASURE_GOLDBAR },
        { PickupType_Treasure_Rings_Red,        SOUND_GAME_TREASURE_RING },
        { PickupType_Treasure_Rings_Green,      SOUND_GAME_TREASURE_RING },
        { PickupType_Treasure_Rings_Blue,       SOUND_GAME_TREASURE_RING },
        { PickupType_Treasure_Rings_Purple,     SOUND_GAME_TREASURE_RING },
        { PickupType_Treasure_Necklace,         SOUND_GAME_TREASURE_GECKO },
        { PickupType_Treasure_Crosses_Red,      SOUND_GAME_TREASURE_CROSS },
        { PickupType_Treasure_Crosses_Green,    SOUND_GAME_TREASURE_CROSS },
        { PickupType_Treasure_Crosses_Blue,     SOUND_GAME_TREASURE_CROSS },
        { PickupType_Treasure_Crosses_Purple,   SOUND_GAME_TREASURE_CROSS },
        { PickupType_Treasure_Scepters_Red,     SOUND_GAME_TREASURE_SCEPTER },
        { PickupType_Treasure_Scepters_Green,   SOUND_GAME_TREASURE_SCEPTER },
        { PickupType_Treasure_Scepters_Blue,    SOUND_GAME_TREASURE_SCEPTER },
        { PickupType_Treasure_Scepters_Purple,  SOUND_GAME_TREASURE_SCEPTER },
        { PickupType_Treasure_Geckos_Red,       SOUND_GAME_TREASURE_GECKO },
        { PickupType_Treasure_Geckos_Green,     SOUND_GAME_TREASURE_GECKO },
        { PickupType_Treasure_Geckos_Blue,      SOUND_GAME_TREASURE_GECKO },
        { PickupType_Treasure_Geckos_Purple,    SOUND_GAME_TREASURE_GECKO },
        { PickupType_Ammo_Deathbag,             SOUND_GAME_PICKUP_AMMUNITION },
        { PickupType_Ammo_Shot,                 SOUND_GAME_PICKUP_AMMUNITION },
        { PickupType_Ammo_Shotbag,              SOUND_GAME_PICKUP_AMMUNITION },
        { PickupType_Powerup_Catnip_1,          SOUND_GAME_PICKUP_CATNIP },
        { PickupType_Powerup_Catnip_2,          SOUND_GAME_PICKUP_CATNIP },
        { PickupType_Health_Breadwater,         SOUND_GAME_PICKUP_FOODITEM },
        { PickupType_Health_25,                 SOUND_GAME_PICKUP_POTION },
        { PickupType_Health_10,                 SOUND_GAME_PICKUP_POTION },
        { PickupType_Health_15,                 SOUND_GAME_PICKUP_POTION },
        { PickupType_Ammo_Magic_5,              SOUND_GAME_PICKUP_MAGIC },
        { PickupType_Ammo_Magic_10,             SOUND_GAME_PICKUP_MAGIC },
        { PickupType_Ammo_Magic_25,             SOUND_GAME_PICKUP_MAGIC },
        { PickupType_Mappiece, "" },
        { PickupType_Warp, "" },
        { PickupType_Treasure_Coins,            SOUND_GAME_TREASURE_COIN },
        { PickupType_Ammo_Dynamite, "" },
        { PickupType_Curse_Ammo, "" },
        { PickupType_Curse_Magic, "" },
        { PickupType_Curse_Health, "" },
        { PickupType_Curse_Death, "" },
        { PickupType_Curse_Treasure, "" },
        { PickupType_Curse_Freeze, "" },
        { PickupType_Treasure_Chalices_Red,     SOUND_GAME_TREASURE_CHALICE },
        { PickupType_Treasure_Chalices_Green,   SOUND_GAME_TREASURE_CHALICE },
        { PickupType_Treasure_Chalices_Blue,    SOUND_GAME_TREASURE_CHALICE },
        { PickupType_Treasure_Chalices_Purple,  SOUND_GAME_TREASURE_CHALICE },
        { PickupType_Treasure_Crowns_Red,       SOUND_GAME_TREASURE_CROWN },
        { PickupType_Treasure_Crowns_Green,     SOUND_GAME_TREASURE_CROWN },
        { PickupType_Treasure_Crowns_Blue,      SOUND_GAME_TREASURE_CROWN },
        { PickupType_Treasure_Crowns_Purple,    SOUND_GAME_TREASURE_CROWN },
        { PickupType_Treasure_Skull_Red,        SOUND_GAME_TREASURE_SKULL },
        { PickupType_Treasure_Skull_Green,      SOUND_GAME_TREASURE_SKULL },
        { PickupType_Treasure_Skull_Blue,       SOUND_GAME_TREASURE_SKULL },
        { PickupType_Treasure_Skull_Purple,     SOUND_GAME_TREASURE_SKULL },
        { PickupType_Powerup_Invisibility, "" },
        { PickupType_Powerup_Invincibility, "" },
        { PickupType_Powerup_Life, "" },
        { PickupType_Powerup_FireSword, "" },
        { PickupType_Powerup_LightningSword, "" },
        { PickupType_Powerup_IceSword, "" },
    };

    //=====================================================================================================================
    // Helper functions
    //=====================================================================================================================

    StrongActorPtr CreateAndReturnActor(TiXmlElement* pData)
    {
        assert(pData && "Failed to create xml data for actor");

        StrongActorPtr pActor = g_pApp->GetGameLogic()->VCreateActor(pData, NULL);
        assert(pActor && "Failed to create actor");

        // Just to be consistent
        shared_ptr<EventData_New_Actor> pNewActorEvent(new EventData_New_Actor(pActor->GetGUID()));
        IEventMgr::Get()->VQueueEvent(pNewActorEvent);

        return pActor;
    }

    void ImageSetToWildcardImagePath(std::string& imageSet)
    {
        std::replace(imageSet.begin(), imageSet.end(), '_', '/');
        if (imageSet.find("GAME/") != std::string::npos)
        {
            imageSet.replace(imageSet.begin(), imageSet.begin() + strlen("GAME/"), "/GAME/IMAGES/");
        }
        else if (imageSet.find("STATES/") != std::string::npos)
        {
            imageSet.replace(imageSet.begin(), imageSet.begin() + strlen("STATES/"), "/STATES/IMAGES/");
        }
        else
        {
            /*LOG_WARNING("Conflicting image set: " + imageSet);
            LOG_WARNING("Assuming you know what you doing - be careful");*/

            return;

            assert(false && "Not implemented image set");
        }

        imageSet += "/*.PID";
    }

    uint32 GetScorePointsFromImageSet(std::string imageSet)
    {
        uint32 points = 0;
        if (imageSet == "GAME_TREASURE_COINS") points = 100;
        else if (imageSet == "GAME_TREASURE_GOLDBARS") points = 500;
        else if (imageSet == "GAME_TREASURE_NECKLACE") points = 10000;
        else if (imageSet.find("GAME_TREASURE_RINGS") != std::string::npos) points = 1500;
        else if (imageSet.find("GAME_TREASURE_CHALICES") != std::string::npos) points = 2500;
        else if (imageSet.find("GAME_TREASURE_CROSSES") != std::string::npos) points = 5000;
        else if (imageSet.find("GAME_TREASURE_SCEPTERS") != std::string::npos) points = 7500;
        else if (imageSet.find("GAME_TREASURE_GECKOS") != std::string::npos) points = 10000;
        else if (imageSet.find("GAME_TREASURE_CROWNS") != std::string::npos) points = 15000;
        else if (imageSet.find("GAME_TREASURE_JEWELEDSKULL") != std::string::npos) points = 25000;

        if (points == 0)
        {
            assert(false && "Invalid treasure");
        }

        return points;
    }

    uint32 GetHealthCountFromImageSet(std::string imageSet)
    {
        uint32 healthCount = 0;
        if (imageSet == "GAME_HEALTH_POTION1") healthCount = 10;
        else if (imageSet == "GAME_HEALTH_POTION2") healthCount = 15;
        else if (imageSet == "GAME_HEALTH_POTION3") healthCount = 25;
        else if (imageSet == "GAME_HEALTH_BREADWATER") healthCount = 5;
        else if (imageSet == "LEVEL_HEALTH") healthCount = 5;

        if (healthCount == 0)
        {
            LOG_ERROR("Offending imageset: " + imageSet);
            assert(false && "Invalid health pickup");
        }

        return healthCount;
    }

    std::pair<std::string, uint32> GetAmmoCountAndTypeFromImageset(const std::string& imageSet)
    {
        if (imageSet == "GAME_AMMO_SHOT") return std::make_pair("Pistol", 10);
        else if (imageSet == "GAME_AMMO_SHOTBAG") return std::make_pair("Pistol", 15);
        else if (imageSet == "GAME_AMMO_DEATHBAG") return std::make_pair("Pistol", 25);
        else if (imageSet == "GAME_MAGIC_GLOW") return std::make_pair("Magic", 5);
        else if (imageSet == "GAME_MAGIC_STARGLOW") return std::make_pair("Magic", 10);
        else if (imageSet == "GAME_MAGIC_MAGICCLAW") return std::make_pair("Magic", 25);
        else if (imageSet == "GAME_DYNAMITE") return std::make_pair("Dynamite", 5);
        else
        {
            assert(false && "Invalid ammo image set");
        }
    }

    std::pair<std::string, uint32> GetPowerupTypeAndDurationFromImageset(const std::string& imageSet)
    {
        if (imageSet == "GAME_CATNIPS_NIP1") return std::make_pair("Catnip", 15000);
        else if (imageSet == "GAME_CATNIPS_NIP2") return std::make_pair("Catnip", 30000);
        else
        {
            assert(false && "Invalid ammo image set");
        }
    }

    std::string GetImageSetFromClawAmmoType(AmmoType ammoType)
    {
        if (ammoType == AmmoType_Pistol)
        {
            return "GAME_BULLETS";
        }
        else if (ammoType == AmmoType_Magic)
        {
            return "GAME_MAGICCLAW";
        }
        else if (ammoType == AmmoType_Dynamite)
        {
            return "GAME_DYNAMITE";
        }

        assert(false && "Unknwon ammo type");

        return "Unknown";
    }

    std::string GetImageSetFromGlitterType(const std::string& glitterType)
    {
        if (glitterType == "Glitter_Yellow") { return "GAME_GLITTER"; }
        else if (glitterType == "Glitter_Red") { return "GAME_GLITTERRED"; }
        else if (glitterType == "Glitter_Green") { return "GAME_GREENGLITTER"; }

        LOG_ERROR("Offending glitter type: " + glitterType);
        assert(false && "Invalid glitter type");

        return "Unknown";
    }

    std::string GetImageSetFromScoreCount(int score)
    {
        if (score == 0) { return "/GAME/IMAGES/POINTS/FRAME0*"; }
        if (score == 100) { return "/GAME/IMAGES/POINTS/FRAME1*"; }
        else if (score == 500) { return "/GAME/IMAGES/POINTS/FRAME2*"; }
        else if (score == 1500) { return "/GAME/IMAGES/POINTS/FRAME3*"; }
        else if (score == 2500) { return "/GAME/IMAGES/POINTS/FRAME4*"; }
        else if (score == 5000) { return "/GAME/IMAGES/POINTS/FRAME5*"; }
        else if (score == 7500) { return "/GAME/IMAGES/POINTS/FRAME6*"; }
        else if (score == 10000) { return "/GAME/IMAGES/POINTS/FRAME7*"; }
        else if (score == 15000) { return "/GAME/IMAGES/POINTS/FRAME8*"; }
        else if (score == 25000) { return "/GAME/IMAGES/POINTS/FRAME9*"; }
        else
        {
            LOG_ERROR("Conflicting score: " + ToStr(score));
            assert(false && "Invalid score number");
        }

        // Never reached but stops compiler from complaining
        return "";
    }

    std::string FixtureTypeToString(FixtureType fixtureType)
    {
        std::string fixtureTypeStr;

        if (fixtureType == FixtureType_Solid) { fixtureTypeStr = "Solid"; }
        else if (fixtureType == FixtureType_Ground) { fixtureTypeStr = "Ground"; }
        else if (fixtureType == FixtureType_Climb) { fixtureTypeStr = "Climb"; }
        else if (fixtureType == FixtureType_Death) { fixtureTypeStr = "Death"; }
        else if (fixtureType == FixtureType_Trigger) { fixtureTypeStr = "Trigger"; }
        else if (fixtureType == FixtureType_Controller) { fixtureTypeStr = "Controller"; }
        else if (fixtureType == FixtureType_Projectile) { fixtureTypeStr = "Projectile"; }
        else if (fixtureType == FixtureType_Crate) { fixtureTypeStr = "Crate"; }
        else if (fixtureType == FixtureType_Pickup) { fixtureTypeStr = "Pickup"; }
        else if (fixtureType == FixtureType_Trigger) { fixtureTypeStr = "Trigger"; }
        else if (fixtureType == FixtureType_PowderKeg) { fixtureTypeStr = "PowderKeg"; }
        else if (fixtureType == FixtureType_Explosion) { fixtureTypeStr = "Explosion"; }
        else if (fixtureType == FixtureType_EnemyAI) { fixtureTypeStr = "EnemyAI"; }
        else if (fixtureType == FixtureType_EnemyAIMeleeSensor) { fixtureTypeStr = "EnemyAIMeleeSensor"; }
        else if (fixtureType == FixtureType_EnemyAIRangedSensor) { fixtureTypeStr = "EnemyAIRangedSensor"; }
        else
        {
            assert(false && "Unknown body type");
        }

        return fixtureTypeStr;
    }

    std::string BodyTypeToString(b2BodyType bodyType)
    {
        std::string bodyTypeStr;

        if (bodyType == b2_staticBody) { bodyTypeStr = "Static"; }
        else if (bodyType == b2_kinematicBody) { bodyTypeStr = "Kinematic"; }
        else if (bodyType == b2_dynamicBody) { bodyTypeStr = "Dynamic"; }
        else
        {
            assert(false && "Unknown body type");
        }

        return bodyTypeStr;
    }

    
    std::vector<std::pair<std::string, std::string>> GetSoundsFromActorLogic(const std::string& logic)
    {
        std::vector <std::pair<std::string, std::string>> soundTypeAndNamePairList;
        if (logic == "Soldier")
        {
            soundTypeAndNamePairList.push_back(std::make_pair(
                std::string("TakeDamage"), std::string(SOUND_LEVEL1_SOLDIER_DAMAGED)));
            soundTypeAndNamePairList.push_back(std::make_pair(
                std::string("Death"), std::string(SOUND_LEVEL1_SOLDIER_DEATH)));
            soundTypeAndNamePairList.push_back(std::make_pair(
                std::string("MeleeAttack"), std::string(SOUND_LEVEL1_SOLDIER_MELEE_ATTACK)));
            soundTypeAndNamePairList.push_back(std::make_pair(
                std::string("RangedAttack"), std::string(SOUND_LEVEL1_SOLDIER_SHOOT)));

        }
        else if (logic == "Officer")
        {
            soundTypeAndNamePairList.push_back(std::make_pair(
                std::string("TakeDamage"), std::string(SOUND_LEVEL1_TAKE_DAMAGE1)));
            soundTypeAndNamePairList.push_back(std::make_pair(
                std::string("Death"), std::string(SOUND_LEVEL1_OFFICER_DEATH1)));
            soundTypeAndNamePairList.push_back(std::make_pair(
                std::string("Death"), std::string(SOUND_LEVEL1_OFFICER_DEATH2)));
            soundTypeAndNamePairList.push_back(std::make_pair(
                std::string("MeleeAttack"), std::string(SOUND_LEVEL1_OFFICER_MELEE_ATTACK)));
        }
        else if (logic == "Rat")
        {
            soundTypeAndNamePairList.push_back(std::make_pair(
                std::string("Death"), std::string(SOUND_LEVEL1_RAT_DEATH)));
            soundTypeAndNamePairList.push_back(std::make_pair(
                std::string("RangedAttack"), std::string(SOUND_LEVEL1_RAT_THROW_BOMB)));
        }
        else
        {
            LOG_ERROR("Unsupported logic: " + logic);
            assert(false && "Unsupported logic");
        }

        return soundTypeAndNamePairList;
    }

    std::string GetSoundPathFromClawPath(const std::string& sound)
    {
        if (sound.find("_") == std::string::npos)
        {
            LOG_WARNING("Cannot convert sound: " + sound);
            return sound;
        }

        std::string soundName = sound;
        std::replace(soundName.begin(), soundName.end(), '_', '/');
        if (soundName.find("GAME/") != std::string::npos)
        {
            soundName.replace(soundName.begin(), soundName.begin() + strlen("GAME/"), "/GAME/SOUNDS/");
            soundName += ".WAV";
        }
        else if (soundName.find("STATES/") != std::string::npos)
        {
            soundName.replace(soundName.begin(), soundName.begin() + strlen("STATES/"), "/STATES/SOUNDS/");
            soundName += ".WAV";
        }
        else if (soundName.find("LEVEL/") != std::string::npos)
        {
            std::string levelName = "LEVEL" + ToStr(1);
            soundName.replace(soundName.begin(), soundName.begin() + strlen("LEVEL/"), 
                "/" + levelName + "/SOUNDS/");
            soundName += ".WAV";
        }
        else
        {
            LOG_ERROR("Conflicting sound: " + sound);
            assert(false && "Invalid sound");
        }

        return soundName;
    }

    //=====================================================================================================================
    // General functions for creating components
    //=====================================================================================================================
    TiXmlElement* CreatePositionComponent(double x, double y)
    {
        TiXmlElement* pComponent = new TiXmlElement("PositionComponent");
        XML_ADD_2_PARAM_ELEMENT("Position", "x", (int)x, "y", (int)y, pComponent);
        return pComponent;
    }

    TiXmlElement* CreateActorRenderComponent(const std::vector<std::string>& imagePaths, int32 zCoord, bool isVisible = true, bool isMirrored = false, bool isInverted = false)
    {
        TiXmlElement* pComponent = new TiXmlElement("ActorRenderComponent");
        XML_ADD_TEXT_ELEMENT("Visible", ToStr(isVisible).c_str(), pComponent);
        XML_ADD_TEXT_ELEMENT("Mirrored", ToStr(isMirrored).c_str(), pComponent);
        XML_ADD_TEXT_ELEMENT("Inverted", ToStr(isInverted).c_str(), pComponent);
        XML_ADD_TEXT_ELEMENT("ZCoord", ToStr(zCoord).c_str(), pComponent);

        for (std::string imagePath : imagePaths)
        {
            XML_ADD_TEXT_ELEMENT("ImagePath", imagePath.c_str(), pComponent);
        }

        return pComponent;
    }

    TiXmlElement* CreateActorRenderComponent(std::string imageSet, int32 zCoord, bool isVisible = true, bool isMirrored = false, bool isInverted = false, bool convertImageSetToWildcard = true)
    {
        TiXmlElement* pComponent = new TiXmlElement("ActorRenderComponent");
        XML_ADD_TEXT_ELEMENT("Visible", ToStr(isVisible).c_str(), pComponent);
        XML_ADD_TEXT_ELEMENT("Mirrored", ToStr(isMirrored).c_str(), pComponent);
        XML_ADD_TEXT_ELEMENT("Inverted", ToStr(isInverted).c_str(), pComponent);
        XML_ADD_TEXT_ELEMENT("ZCoord", ToStr(zCoord).c_str(), pComponent);

        if (convertImageSetToWildcard)
        {
            ImageSetToWildcardImagePath(imageSet);
        }
        XML_ADD_TEXT_ELEMENT("ImagePath", imageSet.c_str(), pComponent);

        return pComponent;
    }

    TiXmlElement* CreateAnimationComponent(std::string animationPath, bool pauseOnStart)
    {
        TiXmlElement* pAnimElem = new TiXmlElement("AnimationComponent");
        XML_ADD_TEXT_ELEMENT("AnimationPath", animationPath.c_str(), pAnimElem);
        XML_ADD_TEXT_ELEMENT("PauseOnStart", ToStr(pauseOnStart).c_str(), pAnimElem);

        return pAnimElem;
    }

    TiXmlElement* CreateCycleAnimationComponent(uint32 cycleTime, bool pauseOnStart = false)
    {
        TiXmlElement* pAnimElem = new TiXmlElement("AnimationComponent");
        std::string cycleStr = "cycle" + ToStr(cycleTime);
        XML_ADD_1_PARAM_ELEMENT("Animation", "type", cycleStr.c_str(), pAnimElem);
        XML_ADD_TEXT_ELEMENT("PauseOnStart", ToStr(pauseOnStart).c_str(), pAnimElem);

        return pAnimElem;
    }

    TiXmlElement* CreateTriggerComponent(int enterCount, bool onceALife, bool isStatic)
    {
        TiXmlElement* pTriggerComponent = new TiXmlElement("TriggerComponent");
        if (onceALife)
        {
            XML_ADD_TEXT_ELEMENT("TriggerOnce", "true", pTriggerComponent);
        }
        else if (enterCount > 0)
        {
            XML_ADD_TEXT_ELEMENT("TriggerFinitedTimes", ToStr(enterCount).c_str(), pTriggerComponent);
        }
        else
        {
            XML_ADD_TEXT_ELEMENT("TriggerUnlimited", "true", pTriggerComponent);
        }
        if (isStatic)
        {
            XML_ADD_TEXT_ELEMENT("IsStatic", "true", pTriggerComponent);
        }

        return pTriggerComponent;
    }

    TiXmlElement* CreatePhysicsComponent(
        std::string bodyTypeStr,
        bool hasFootSensor,
        bool hasCapsuleShape,
        bool hasBulletBehaviour,
        bool hasSensorBehaviour,
        std::string fixtureTypeStr,
        Point position,
        Point positionOffset,
        std::string collisionShape,
        Point size,
        float gravityScale,
        bool hasInitialSpeed,
        bool hasInitialImpulse,
        Point initialSpeed,
        /*CollisionFlag*/ uint32 collisionFlag,
        uint32 collisionMask,
        float density,
        float friction,
        float restitution,
        std::string prefabType = "")
    {
        TiXmlElement* pPhysicsComponent = new TiXmlElement("PhysicsComponent");
        XML_ADD_TEXT_ELEMENT("BodyType", bodyTypeStr.c_str(), pPhysicsComponent);
        XML_ADD_TEXT_ELEMENT("HasFootSensor", ToStr(hasFootSensor).c_str(), pPhysicsComponent);
        XML_ADD_TEXT_ELEMENT("HasCapsuleShape", ToStr(hasCapsuleShape).c_str(), pPhysicsComponent);
        XML_ADD_TEXT_ELEMENT("HasBulletBehaviour", ToStr(hasBulletBehaviour).c_str(), pPhysicsComponent);
        XML_ADD_TEXT_ELEMENT("HasSensorBehaviour", ToStr(hasSensorBehaviour).c_str(), pPhysicsComponent);
        XML_ADD_TEXT_ELEMENT("FixtureType", fixtureTypeStr.c_str(), pPhysicsComponent);
        XML_ADD_2_PARAM_ELEMENT("PositionOffset", "x", positionOffset.x, "y", positionOffset.y, pPhysicsComponent);
        XML_ADD_TEXT_ELEMENT("CollisionShape", collisionShape.c_str(), pPhysicsComponent);
        XML_ADD_2_PARAM_ELEMENT("CollisionSize", "width", size.x, "height", size.y, pPhysicsComponent);
        XML_ADD_TEXT_ELEMENT("GravityScale", ToStr(gravityScale).c_str(), pPhysicsComponent);
        XML_ADD_TEXT_ELEMENT("HasInitialSpeed", ToStr(hasInitialSpeed).c_str(), pPhysicsComponent);
        XML_ADD_TEXT_ELEMENT("HasInitialImpulse", ToStr(hasInitialImpulse).c_str(), pPhysicsComponent);
        XML_ADD_2_PARAM_ELEMENT("InitialSpeed", "x", initialSpeed.x, "y", initialSpeed.y, pPhysicsComponent);
        XML_ADD_TEXT_ELEMENT("CollisionFlag", ToStr(collisionFlag).c_str(), pPhysicsComponent);
        XML_ADD_TEXT_ELEMENT("CollisionMask", ToStr(collisionMask).c_str(), pPhysicsComponent);
        XML_ADD_TEXT_ELEMENT("Friction", ToStr(friction).c_str(), pPhysicsComponent);
        XML_ADD_TEXT_ELEMENT("Density", ToStr(density).c_str(), pPhysicsComponent);
        XML_ADD_TEXT_ELEMENT("Restitution", ToStr(restitution).c_str(), pPhysicsComponent);
        XML_ADD_TEXT_ELEMENT("PrefabType", prefabType.c_str(), pPhysicsComponent);

        return pPhysicsComponent;
    }

    TiXmlElement* CreatePhysicsComponent(const ActorBodyDef* pBodyDef)
    {
        TiXmlElement* pPhysicsComponent = new TiXmlElement("PhysicsComponent");

        std::string bodyTypeStr = BodyTypeToString(pBodyDef->bodyType);
        std::string fixtureTypeStr = FixtureTypeToString(pBodyDef->fixtureType);

        XML_ADD_TEXT_ELEMENT("BodyType", bodyTypeStr.c_str(), pPhysicsComponent);
        XML_ADD_TEXT_ELEMENT("HasFootSensor", ToStr(pBodyDef->addFootSensor).c_str(), pPhysicsComponent);
        XML_ADD_TEXT_ELEMENT("HasCapsuleShape", ToStr(pBodyDef->makeCapsule).c_str(), pPhysicsComponent);
        XML_ADD_TEXT_ELEMENT("HasBulletBehaviour", ToStr(pBodyDef->makeBullet).c_str(), pPhysicsComponent);
        XML_ADD_TEXT_ELEMENT("HasSensorBehaviour", ToStr(pBodyDef->makeSensor).c_str(), pPhysicsComponent);
        XML_ADD_TEXT_ELEMENT("FixtureType", fixtureTypeStr.c_str(), pPhysicsComponent);
        XML_ADD_2_PARAM_ELEMENT("PositionOffset", "x", pBodyDef->positionOffset.x, "y", pBodyDef->positionOffset.y, pPhysicsComponent);
        XML_ADD_TEXT_ELEMENT("CollisionShape", pBodyDef->collisionShape.c_str(), pPhysicsComponent);
        XML_ADD_2_PARAM_ELEMENT("CollisionSize", "width", pBodyDef->size.x, "height", pBodyDef->size.y, pPhysicsComponent);
        XML_ADD_TEXT_ELEMENT("GravityScale", ToStr(pBodyDef->gravityScale).c_str(), pPhysicsComponent);
        XML_ADD_TEXT_ELEMENT("HasInitialSpeed", ToStr(pBodyDef->setInitialSpeed).c_str(), pPhysicsComponent);
        XML_ADD_TEXT_ELEMENT("HasInitialImpulse", ToStr(pBodyDef->setInitialImpulse).c_str(), pPhysicsComponent);
        XML_ADD_2_PARAM_ELEMENT("InitialSpeed", "x", pBodyDef->initialSpeed.x, "y", pBodyDef->initialSpeed.y, pPhysicsComponent);
        XML_ADD_TEXT_ELEMENT("CollisionFlag", ToStr(pBodyDef->collisionFlag).c_str(), pPhysicsComponent);
        XML_ADD_TEXT_ELEMENT("CollisionMask", ToStr(pBodyDef->collisionMask).c_str(), pPhysicsComponent);
        XML_ADD_TEXT_ELEMENT("Friction", ToStr(pBodyDef->friction).c_str(), pPhysicsComponent);
        XML_ADD_TEXT_ELEMENT("Density", ToStr(pBodyDef->density).c_str(), pPhysicsComponent);
        XML_ADD_TEXT_ELEMENT("Restitution", ToStr(pBodyDef->restitution).c_str(), pPhysicsComponent);
        XML_ADD_TEXT_ELEMENT("PrefabType", pBodyDef->prefabType.c_str(), pPhysicsComponent);

        // Convert actor's fixtures to xml
        for (ActorFixtureDef fixture : pBodyDef->fixtureList)
        {
            TiXmlElement* pFixtureElem = new TiXmlElement("ActorFixture");

            XML_ADD_TEXT_ELEMENT("FixtureType", FixtureTypeToString(fixture.fixtureType).c_str(), pFixtureElem);
            XML_ADD_TEXT_ELEMENT("CollisionShape", fixture.collisionShape.c_str(), pFixtureElem);
            XML_ADD_TEXT_ELEMENT("IsSensor", ToStr(fixture.isSensor).c_str(), pFixtureElem);
            XML_ADD_2_PARAM_ELEMENT("Size", "width", fixture.size.x, "height", fixture.size.y, pFixtureElem);
            XML_ADD_2_PARAM_ELEMENT("Offset", "x", fixture.offset.x, "y", fixture.offset.y, pFixtureElem);
            XML_ADD_TEXT_ELEMENT("CollisionFlag", ToStr(fixture.collisionFlag).c_str(), pFixtureElem);
            XML_ADD_TEXT_ELEMENT("CollisionMask", ToStr(fixture.collisionMask).c_str(), pFixtureElem);
            XML_ADD_TEXT_ELEMENT("Friction", ToStr(fixture.friction).c_str(), pFixtureElem);
            XML_ADD_TEXT_ELEMENT("Density", ToStr(fixture.density).c_str(), pFixtureElem);
            XML_ADD_TEXT_ELEMENT("Restitution", ToStr(fixture.restitution).c_str(), pFixtureElem);

            pPhysicsComponent->LinkEndChild(pFixtureElem);
        }

        return pPhysicsComponent;
    }

    TiXmlElement* CreateFollowableComponent(Point offset, std::string imageSet, std::string animPath)
    {
        TiXmlElement* pFollowableComponentElem = new TiXmlElement("FollowableComponent");
        XML_ADD_2_PARAM_ELEMENT("Offset", "x", offset.x, "y", offset.y, pFollowableComponentElem);
        XML_ADD_TEXT_ELEMENT("ImageSet", imageSet.c_str(), pFollowableComponentElem);
        XML_ADD_TEXT_ELEMENT("AnimationPath", animPath.c_str(), pFollowableComponentElem);

        return pFollowableComponentElem;
    }

    TiXmlElement* CreateLootComponent(const std::vector<PickupType>& loot)
    {
        TiXmlElement* pLootComponent = new TiXmlElement("LootComponent");
        
        for (auto item : loot)
        {
            XML_ADD_TEXT_ELEMENT("Item", ToStr(item).c_str(), pLootComponent);
        }

        if (loot.empty())
        {
            XML_ADD_TEXT_ELEMENT("Item", ToStr(PickupType_Treasure_Coins).c_str(), pLootComponent);
        }

        return pLootComponent;
    }

    TiXmlElement* CreateDestroyableComponent(bool deleteOnDestruction, const std::string& deathAnimName, const std::vector<std::string>& deathSounds, bool removeFromPhysics = true)
    {
        TiXmlElement* pDestroyableComponent = new TiXmlElement("DestroyableComponent");

        XML_ADD_TEXT_ELEMENT("DeleteOnDestruction", ToStr(deleteOnDestruction).c_str(), pDestroyableComponent);
        XML_ADD_TEXT_ELEMENT("RemoveFromPhysics", ToStr(removeFromPhysics).c_str(), pDestroyableComponent);
        if (!deathAnimName.empty())
        {
            XML_ADD_TEXT_ELEMENT("DeathAnimationName", deathAnimName.c_str(), pDestroyableComponent);
        }
        for (auto deathSound : deathSounds)
        {
            XML_ADD_TEXT_ELEMENT("DeathSound", deathSound.c_str(), pDestroyableComponent);
        }

        return pDestroyableComponent;
    }

    TiXmlElement* CreateHealthComponent(int currentHealth, int maxHealth)
    {
        TiXmlElement* pHealthComponent = new TiXmlElement("HealthComponent");

        XML_ADD_TEXT_ELEMENT("Health", ToStr(currentHealth).c_str(), pHealthComponent);
        XML_ADD_TEXT_ELEMENT("MaxHealth", ToStr(maxHealth).c_str(), pHealthComponent);

        return pHealthComponent;
    }

    TiXmlElement* CreateExplodeableComponent(Point explosionSize, int damage, int explodingTime = 100)
    {
        TiXmlElement* pExplodeableComponent = new TiXmlElement("ExplodeableComponent");

        XML_ADD_2_PARAM_ELEMENT("ExplosionSize", "width", ToStr(explosionSize.x).c_str(), "height", ToStr(explosionSize.y).c_str(), pExplodeableComponent);
        XML_ADD_TEXT_ELEMENT("Damage", ToStr(damage).c_str(), pExplodeableComponent);
        XML_ADD_TEXT_ELEMENT("ExplodingTime", ToStr(explodingTime).c_str(), pExplodeableComponent);

        return pExplodeableComponent;
    }

    TiXmlElement* CreateAreaDamageComponent(int damage, int areaDuration = 100)
    {
        TiXmlElement* pAreaDamageComponent = new TiXmlElement("AreaDamageComponent");

        XML_ADD_TEXT_ELEMENT("Damage", ToStr(damage).c_str(), pAreaDamageComponent);
        XML_ADD_TEXT_ELEMENT("Duration", ToStr(areaDuration).c_str(), pAreaDamageComponent);

        return pAreaDamageComponent;
    }

    TiXmlElement* CreateXmlData_GlitterComponent(std::string glitterType, bool spawnImmediate, bool followOwner)
    {
        TiXmlElement* pGlitterComponent = new TiXmlElement("GlitterComponent");

        XML_ADD_TEXT_ELEMENT("GlitterType", glitterType.c_str(), pGlitterComponent);
        XML_ADD_TEXT_ELEMENT("SpawnImmediate", ToStr(spawnImmediate).c_str(), pGlitterComponent);
        XML_ADD_TEXT_ELEMENT("FollowOwner", ToStr(followOwner).c_str(), pGlitterComponent);

        return pGlitterComponent;
    }

    

    ActorFixtureDef CreateActorAgroRangeFixture(Point size, Point offset, FixtureType fixtureType)
    {
        ActorFixtureDef fixtureDef;

        fixtureDef.fixtureType = fixtureType;
        fixtureDef.collisionFlag = CollisionFlag_DynamicActor;
        fixtureDef.collisionMask = CollisionFlag_Controller;
        fixtureDef.isSensor = true;
        fixtureDef.size = size;
        fixtureDef.offset = offset;

        return fixtureDef;
    }

    TiXmlElement* CreateXmlData_PatrolState(uint32 animationDelay, double patrolSpeed, int leftPatrolBorder, int rightPatrolBorder, std::string walkAnimation, std::vector<std::string> idleAnimations, bool retainDirection = false)
    {
        TiXmlElement* pPatrolStateElem = new TiXmlElement("PatrolEnemyAIStateComponent");
        XML_ADD_TEXT_ELEMENT("PatrolSpeed", ToStr(patrolSpeed).c_str(), pPatrolStateElem);
        XML_ADD_TEXT_ELEMENT("LeftPatrolBorder", ToStr(leftPatrolBorder).c_str(), pPatrolStateElem);
        XML_ADD_TEXT_ELEMENT("RightPatrolBorder", ToStr(rightPatrolBorder).c_str(), pPatrolStateElem);
        XML_ADD_TEXT_ELEMENT("RetainDirection", ToStr(retainDirection).c_str(), pPatrolStateElem);

        TiXmlElement* pWalkActionElem = new TiXmlElement("WalkAction");
        XML_ADD_TEXT_ELEMENT("Animation", walkAnimation.c_str(), pWalkActionElem);
        pPatrolStateElem->LinkEndChild(pWalkActionElem);

        if (!idleAnimations.empty())
        {
            TiXmlElement* pIdleActionElem = new TiXmlElement("IdleAction");
            XML_ADD_TEXT_ELEMENT("AnimationDelay", ToStr(animationDelay).c_str(), pIdleActionElem);
            for (auto idleAnim : idleAnimations)
            {
                XML_ADD_TEXT_ELEMENT("Animation", idleAnim.c_str(), pIdleActionElem);
            }
            pPatrolStateElem->LinkEndChild(pIdleActionElem);
        }

        return pPatrolStateElem;
    }

    TiXmlElement* CreatePredefinedMoveComponent(std::vector<PredefinedMove>& moves, bool isInfinite)
    {
        TiXmlElement* pPredefinedMovesElem = new TiXmlElement("PredefinedMoveComponent");

        for (PredefinedMove& move : moves)
        {
            TiXmlElement* pMoveElem = new TiXmlElement("PredefinedMove");
            XML_ADD_TEXT_ELEMENT("DurationMiliseconds", ToStr(move.msDuration).c_str(), pMoveElem);
            XML_ADD_2_PARAM_ELEMENT("PixelsPerSecond", "x", ToStr(move.pixelsPerSecond.x).c_str(), 
                "y", ToStr(move.pixelsPerSecond.y).c_str(), pMoveElem);
            XML_ADD_TEXT_ELEMENT("Sound", move.soundToPlay.c_str(), pMoveElem);
            pPredefinedMovesElem->LinkEndChild(pMoveElem);
        }

        XML_ADD_TEXT_ELEMENT("IsInfinite", ToStr(isInfinite).c_str(), pPredefinedMovesElem);

        return pPredefinedMovesElem;
    }

    TiXmlElement* CreatePredefinedMoveComponent(const PredefinedMove& move, bool isInfinite)
    {
        std::vector<PredefinedMove> moves = { move };
        return CreatePredefinedMoveComponent(moves, isInfinite);
    }

    TiXmlElement* CreateXmlData_EnemyAttackActionState(std::vector<EnemyAttackAction>& attackActions)
    {
        assert(!attackActions.empty());

        std::string componentName;
        if (attackActions[0].attackDamageType == DamageType_MeleeAttack)
        {
            componentName = "MeleeAttackAIStateComponent";
        }
        else if (attackActions[0].attackDamageType == DamageType_Bullet)
        {
            componentName = "RangedAttackAIStateComponent";
        }
        else
        {
            assert(false && "Unknown damage type");
        }

        TiXmlElement* pAttackStateElem = new TiXmlElement(componentName.c_str());

        TiXmlElement* pAttacksElem = new TiXmlElement("Attacks");
        for (auto attackAction : attackActions)
        {
            TiXmlElement* pAttackActionElem = new TiXmlElement("AttackAction");
            XML_ADD_TEXT_ELEMENT("Animation", attackAction.animation.c_str(), pAttackActionElem);
            XML_ADD_TEXT_ELEMENT("AttackAnimFrameIdx", ToStr(attackAction.attackAnimFrameIdx).c_str(), pAttackActionElem);
            XML_ADD_TEXT_ELEMENT("AttackType", ToStr(attackAction.attackDamageType).c_str(), pAttackActionElem);
            XML_ADD_TEXT_ELEMENT("AttackFxImageSet", attackAction.attackFxImageSet.c_str(), pAttackActionElem);
            XML_ADD_2_PARAM_ELEMENT("AttackSpawnPositionOffset", "x", attackAction.attackSpawnPositionOffset.x, "y", attackAction.attackSpawnPositionOffset.y, pAttackActionElem);
            XML_ADD_2_PARAM_ELEMENT("AttackAreaSize", "width", attackAction.attackAreaSize.x, "height", attackAction.attackAreaSize.y, pAttackActionElem);
            XML_ADD_TEXT_ELEMENT("Damage", ToStr(attackAction.damage).c_str(), pAttackActionElem);

            pAttacksElem->LinkEndChild(pAttackActionElem);
        }

        pAttackStateElem->LinkEndChild(pAttacksElem);

        return pAttackStateElem;
    }

    //=====================================================================================================================
    // Specific functions for creating specific actors
    //=====================================================================================================================

    // TODO: What is this function specifically for ? Only dynamically spawned pickups ?
    TiXmlElement* CreateXmlData_GeneralPickupActor(std::string imageSet, Point position, int32 zCoord, bool isStatic)
    {
        TiXmlElement* pActorElem = new TiXmlElement("Actor");
        pActorElem->SetAttribute("Type", imageSet.c_str());
        
        pActorElem->LinkEndChild(CreatePositionComponent(position.x, position.y));

        ImageSetToWildcardImagePath(imageSet);
        std::vector<std::string> imagePaths;
        imagePaths.push_back(imageSet);
        pActorElem->LinkEndChild(CreateActorRenderComponent(imagePaths, zCoord));

        pActorElem->LinkEndChild(CreateTriggerComponent(1, false, isStatic));

        srand((long)pActorElem + time(NULL));
        double speedX = 0.5 + (rand() % 100) / 50.0;
        double speedY = -(1 + (rand() % 100) / 50.0);

        if (rand() % 2 == 1) { speedX *= -1; }

        ActorBodyDef bodyDef;
        if (isStatic)
        {
            bodyDef.bodyType = b2_staticBody;
        }
        else
        {
            bodyDef.bodyType = b2_dynamicBody;
        }
        bodyDef.makeSensor = false;
        bodyDef.fixtureType = FixtureType_Pickup;
        bodyDef.position = position;
        bodyDef.gravityScale = 0.8f;
        bodyDef.setInitialSpeed = true;
        bodyDef.initialSpeed = Point(speedX, speedY);
        bodyDef.collisionFlag = CollisionFlag_Pickup;
        bodyDef.collisionMask = (CollisionFlag_Death | CollisionFlag_Ground | CollisionFlag_Solid);
        bodyDef.density = 10.0f;
        bodyDef.friction = 0.18f;
        bodyDef.restitution = 0.5f;

        ActorFixtureDef fixtureDef;
        fixtureDef.fixtureType = FixtureType_Trigger;
        fixtureDef.collisionFlag = CollisionFlag_Pickup;
        fixtureDef.collisionMask = CollisionFlag_Controller;
        fixtureDef.isSensor = true;
        bodyDef.fixtureList.push_back(fixtureDef);

        pActorElem->LinkEndChild(CreatePhysicsComponent(&bodyDef));

        pActorElem->LinkEndChild(CreateXmlData_GlitterComponent("Glitter_Yellow", isStatic, false));

        return pActorElem;
    }

    TiXmlElement* CreateXmlData_SoundTriggerActor(const std::string& sound, Point position, Point size, int enterCount, bool activateDialog)
    {
        // General stuff

        TiXmlElement* pActorElem = new TiXmlElement("Actor");
        pActorElem->SetAttribute("Type", sound.c_str());

        pActorElem->LinkEndChild(CreatePositionComponent(position.x, position.y));
        pActorElem->LinkEndChild(CreateTriggerComponent(enterCount, false, true));

        ActorBodyDef bodyDef;
        bodyDef.makeSensor = true;
        bodyDef.bodyType = b2_staticBody;
        bodyDef.fixtureType = FixtureType_Pickup;
        bodyDef.position = position;
        bodyDef.collisionFlag = CollisionFlag_Pickup;
        bodyDef.collisionMask = CollisionFlag_Controller;
        bodyDef.fixtureType = FixtureType_Trigger;
        bodyDef.size = size;

        pActorElem->LinkEndChild(CreatePhysicsComponent(&bodyDef));

        // SoundTrigger specific
        TiXmlElement* pSoundTriggerElem = new TiXmlElement("SoundTriggerComponent");

        XML_ADD_TEXT_ELEMENT("EnterCount", ToStr(enterCount).c_str(), pSoundTriggerElem);
        XML_ADD_TEXT_ELEMENT("ActivateDialog", ToStr(activateDialog).c_str(), pSoundTriggerElem);

        std::string soundPath = GetSoundPathFromClawPath(sound);
        XML_ADD_TEXT_ELEMENT("Sound", soundPath.c_str(), pSoundTriggerElem);

        pActorElem->LinkEndChild(pSoundTriggerElem);

        return pActorElem;
    }

    TiXmlElement* CreateXmlData_SoundTriggerActor(const std::string& sound, const std::string& logicName, Point position, SDL_Rect presetPosition, int enterCount)
    {
        Point size;
        if (logicName.find("Tiny") != std::string::npos)
        {
            size.Set(32, 32);
        }
        else if (logicName.find("Small") != std::string::npos)
        {
            size.Set(64, 64);
        }
        else if (logicName.find("Big") != std::string::npos)
        {
            size.Set(256, 256);
        }
        else if (logicName.find("Huge") != std::string::npos)
        {
            size.Set(512, 512);
        }
        else if (logicName.find("Wide") != std::string::npos)
        {
            size.Set(200, 64);
        }
        else if (logicName.find("Tall") != std::string::npos)
        {
            size.Set(64, 200);
        }
        else
        {
            size.Set(128, 128);
        }

        bool activateDialog = logicName.find("ClawDialog") != std::string::npos;

        // Position is already preset
        if (presetPosition.x != 0)
        {
            //position.Set(presetPosition.x, presetPosition.y);
            //size.Set(presetPosition.w - presetPosition.x, presetPosition.h - presetPosition.y);

            size.x = std::min((int)size.x, presetPosition.w - presetPosition.x);
            size.y = std::min((int)size.y, presetPosition.h - presetPosition.y);
        }

        return CreateXmlData_SoundTriggerActor(sound, position, size, enterCount, activateDialog);
    }

    TiXmlElement* CreateXmlData_GlobalAmbientSoundActor(
        const std::string& sound,
        int soundVolume,
        int minTimeOff,
        int maxTimeOff,
        int minTimeOn,
        int maxTimeOn,
        bool isLooping)
    {
        TiXmlElement* pActorElem = new TiXmlElement("Actor");
        pActorElem->SetAttribute("Type", sound.c_str());

        std::string soundPath = GetSoundPathFromClawPath(sound);

        TiXmlElement* pGlobalSoundComponent = new TiXmlElement("GlobalAmbientSoundComponent");
        XML_ADD_TEXT_ELEMENT("Sound", soundPath.c_str(), pGlobalSoundComponent);
        XML_ADD_TEXT_ELEMENT("SoundVolume", ToStr(soundVolume).c_str(), pGlobalSoundComponent);
        XML_ADD_TEXT_ELEMENT("MinTimeOff", ToStr(minTimeOff).c_str(), pGlobalSoundComponent);
        XML_ADD_TEXT_ELEMENT("MaxTimeOff", ToStr(maxTimeOff).c_str(), pGlobalSoundComponent);
        XML_ADD_TEXT_ELEMENT("MinTimeOn", ToStr(minTimeOn).c_str(), pGlobalSoundComponent);
        XML_ADD_TEXT_ELEMENT("MaxTimeOn", ToStr(maxTimeOn).c_str(), pGlobalSoundComponent);
        XML_ADD_TEXT_ELEMENT("IsLooping", ToStr(isLooping).c_str(), pGlobalSoundComponent);

        pActorElem->LinkEndChild(pGlobalSoundComponent);

        return pActorElem;
    }

    TiXmlElement* CreateXmlData_TreasurePickupActor(std::string imageSet, std::string pickupSound, Point position, bool isStatic)
    {
        TiXmlElement* pActor = CreateXmlData_GeneralPickupActor(imageSet, position, 1000, isStatic);

        TiXmlElement* pTreasurePickupComponent = new TiXmlElement("TreasurePickupComponent");
        XML_ADD_TEXT_ELEMENT("ScorePoints", ToStr(GetScorePointsFromImageSet(imageSet)).c_str(), pTreasurePickupComponent);
        XML_ADD_TEXT_ELEMENT("PickupSound", pickupSound.c_str(), pTreasurePickupComponent);
        pActor->LinkEndChild(pTreasurePickupComponent);

        // Coins have animation
        if (imageSet.find("COIN") != std::string::npos)
        {
            pActor->LinkEndChild(CreateCycleAnimationComponent(99, false));
        }

        return pActor;
    }

    TiXmlElement* CreateXmlData_AmmoPickupActor(std::string imageSet, std::string pickupSound, Point position, bool isStatic)
    {
        TiXmlElement* pActor = CreateXmlData_GeneralPickupActor(imageSet, position, 1000, isStatic);

        TiXmlElement* pAmmoPickupComponent = new TiXmlElement("AmmoPickupComponent");
        std::pair<std::string, uint32> ammoPair = GetAmmoCountAndTypeFromImageset(imageSet);
        XML_ADD_2_PARAM_ELEMENT("Ammo", "ammoType", ammoPair.first.c_str(), "ammoCount", ammoPair.second, pAmmoPickupComponent);
        XML_ADD_TEXT_ELEMENT("PickupSound", pickupSound.c_str(), pAmmoPickupComponent);
        pActor->LinkEndChild(pAmmoPickupComponent);

        return pActor;
    }

    TiXmlElement* CreateXmlData_LifePickupActor(std::string imageSet, std::string pickupSound, Point position, bool isStatic)
    {
        TiXmlElement* pActor = CreateXmlData_GeneralPickupActor(imageSet, position, 1000, isStatic);

        TiXmlElement* pLifePickupComponent = new TiXmlElement("LifePickupComponent");
        XML_ADD_TEXT_ELEMENT("Lives", ToStr(1).c_str(), pLifePickupComponent);
        XML_ADD_TEXT_ELEMENT("PickupSound", pickupSound.c_str(), pLifePickupComponent);
        pActor->LinkEndChild(pLifePickupComponent);

        return pActor;
    }

    TiXmlElement* CreateXmlData_HealthPickupActor(std::string imageSet, std::string pickupSound, Point position, bool isStatic)
    {
        TiXmlElement* pActor = CreateXmlData_GeneralPickupActor(imageSet, position, 1000, isStatic);

        TiXmlElement* pHealthPickupComponent = new TiXmlElement("HealthPickupComponent");
        XML_ADD_TEXT_ELEMENT("Health", ToStr(GetHealthCountFromImageSet(imageSet)).c_str(), pHealthPickupComponent);
        XML_ADD_TEXT_ELEMENT("PickupSound", pickupSound.c_str(), pHealthPickupComponent);
        pActor->LinkEndChild(pHealthPickupComponent);

        return pActor;
    }

    TiXmlElement* CreateXmlData_PowerupPickupActor(std::string imageSet, std::string pickupSound, Point position, bool isStatic)
    {
        TiXmlElement* pActor = CreateXmlData_GeneralPickupActor(imageSet, position, 5000, isStatic);

        TiXmlElement* pPowerupPickupComponent = new TiXmlElement("PowerupPickupComponent");
        std::pair<std::string, uint32> powerupPair = GetPowerupTypeAndDurationFromImageset(imageSet);
        XML_ADD_TEXT_ELEMENT("Type", powerupPair.first.c_str(), pPowerupPickupComponent);
        XML_ADD_TEXT_ELEMENT("Duration", ToStr(powerupPair.second).c_str(), pPowerupPickupComponent);
        XML_ADD_TEXT_ELEMENT("PickupSound", pickupSound.c_str(), pPowerupPickupComponent);
        pActor->LinkEndChild(pPowerupPickupComponent);

        return pActor;
    }

    TiXmlElement* CreateXmlData_PowerupSparkleActor(std::string imageSet)
    {
        TiXmlElement* pActor = new TiXmlElement("Actor");
        pActor->SetAttribute("Type", imageSet.c_str());

        pActor->LinkEndChild(CreatePositionComponent(0, 0));
        pActor->LinkEndChild(CreateActorRenderComponent(imageSet, 8000, false));
        pActor->LinkEndChild(CreateCycleAnimationComponent(75));

        TiXmlElement* pPowerupSparkleAIComponent = new TiXmlElement("PowerupSparkleAIComponent");
        pActor->LinkEndChild(pPowerupSparkleAIComponent);

        return pActor;
    }

    TiXmlElement* CreateXmlData_ClawProjectileActor(AmmoType ammoType, Direction direction, Point position)
    {
        std::string imageSet = GetImageSetFromClawAmmoType(ammoType);

        TiXmlElement* pActor = new TiXmlElement("Actor");
        pActor->SetAttribute("Type", imageSet.c_str());

        double speed = 9.5;
        if (direction == Direction_Left) { speed *= -1; }

        CollisionFlag collisionFlag = CollisionFlag_Bullet;
        if (ammoType == AmmoType_Magic) { collisionFlag = CollisionFlag_Magic; }
        else if (ammoType == AmmoType_Dynamite) { collisionFlag = CollisionFlag_Explosion; }

        pActor->LinkEndChild(CreatePositionComponent(position.x, position.y));
        pActor->LinkEndChild(CreateActorRenderComponent(imageSet.c_str(), 5000));
        pActor->LinkEndChild(CreatePhysicsComponent(
            "Dynamic",  // Type - "Dynamic", "Kinematic", "Static"
            false,      // Has foot sensor ?
            false,      // Has capsule shape ?
            true,       // Has bullet behaviour ?
            true,       // Has sensor behaviour ?
            "Projectile",  // Fixture type
            position,      // Position
            Point(0, 0),   // Offset - where to move the body upon its placement
            "Rectangle",   // Body shape - "Rectangle" or "Circle"
            Point(0, 0),   // Size - Leave blank if you want size to be determined by its default image
            0.0f,          // Gravity scale - set to 0.0f if no gravity is desired
            true,          // Has any initial speed ?
            false,
            Point(speed, 0), // If it does, specify it here
            collisionFlag,  // Collision flag - e.g. What is this actor ?
            (CollisionFlag_Crate | CollisionFlag_PowderKeg | CollisionFlag_DynamicActor | CollisionFlag_Solid),  // Collision mask - e.g. With what does this actor collide with ?
            0.0f,  // Density - determines if this character bounces
            0.0f, // Friction - with floor and so
            0.0f)); // Restitution - makes object bounce

        if (ammoType == AmmoType_Magic)
        {
            pActor->LinkEndChild(CreateCycleAnimationComponent(75));
        }

        std::string projectileTypeStr;
        int32 damage = 0;
        if (ammoType == AmmoType_Pistol) { projectileTypeStr = "Bullet"; damage = 20; }
        else if (ammoType == AmmoType_Magic) { projectileTypeStr = "Magic"; damage = 50; }
        else if (ammoType == AmmoType_Dynamite) { projectileTypeStr = "Dynamite"; damage = 50; }
        else { assert(false && "Unknown projectile"); }

        TiXmlElement* pProjectileAIComponent = new TiXmlElement("ProjectileAIComponent");
        XML_ADD_TEXT_ELEMENT("Damage", ToStr(damage).c_str(), pProjectileAIComponent);
        XML_ADD_TEXT_ELEMENT("ProjectileType", projectileTypeStr.c_str(), pProjectileAIComponent);
        XML_ADD_2_PARAM_ELEMENT("Speed", "x", ToStr(speed).c_str(), "y", "0", pProjectileAIComponent);
        pActor->LinkEndChild(pProjectileAIComponent);

        return pActor;
    }

    TiXmlElement* CreateXmlData_ProjectileActor(std::string imageSet, uint32 damage, DamageType damageType, Direction direction, Point position, CollisionFlag collisionFlag, uint32 collisionMask)
    {
        TiXmlElement* pActor = new TiXmlElement("Actor");
        pActor->SetAttribute("Type", imageSet.c_str());

        double speed = 9.5;
        if (direction == Direction_Left) { speed *= -1; }

        pActor->LinkEndChild(CreatePositionComponent(position.x, position.y));
        pActor->LinkEndChild(CreateActorRenderComponent(imageSet.c_str(), 5000));

        ActorBodyDef bodyDef;
        bodyDef.bodyType = b2_dynamicBody;
        bodyDef.makeSensor = true;
        bodyDef.fixtureType = FixtureType_Projectile;
        bodyDef.collisionFlag = collisionFlag;
        bodyDef.collisionMask = collisionMask;
        bodyDef.gravityScale = 0.0f;
        bodyDef.setInitialSpeed = true;
        bodyDef.initialSpeed = Point(speed, 0);

        pActor->LinkEndChild(CreatePhysicsComponent(&bodyDef));

        TiXmlElement* pProjectileAIComponent = new TiXmlElement("ProjectileAIComponent");
        XML_ADD_TEXT_ELEMENT("Damage", ToStr(damage).c_str(), pProjectileAIComponent);
        XML_ADD_TEXT_ELEMENT("ProjectileType", "Bullet", pProjectileAIComponent);
        XML_ADD_2_PARAM_ELEMENT("Speed", "x", ToStr(speed).c_str(), "y", "0", pProjectileAIComponent);
        pActor->LinkEndChild(pProjectileAIComponent);

        return pActor;
    }

    TiXmlElement* CreateXmlData_CrateActor(std::string imageSet, Point position, const std::vector<PickupType>& loot, uint32 health, int32 zCoord)
    {
        TiXmlElement* pActor = new TiXmlElement("Actor");
        pActor->SetAttribute("Type", imageSet.c_str());

        pActor->LinkEndChild(CreatePositionComponent(position.x, position.y));
        pActor->LinkEndChild(CreateActorRenderComponent(imageSet.c_str(), zCoord));
        pActor->LinkEndChild(CreatePhysicsComponent(
            "Dynamic",  // Type - "Dynamic", "Kinematic", "Static"
            false,      // Has foot sensor ?
            false,      // Has capsule shape ?
            true,       // Has bullet behaviour ?
            false,       // Has sensor behaviour ?
            "Crate",    // Fixture type
            position,      // Position
            Point(0, 0),   // Offset - where to move the body upon its placement
            "Rectangle",   // Body shape - "Rectangle" or "Circle"
            Point(44, 40),   // Size - Leave blank if you want size to be determined by its default image
            0.8f,          // Gravity scale - set to 0.0f if no gravity is desired
            true,          // Has any initial speed ?
            false,         // Has initial impulse ?
            Point(0, 0), // If it does, specify it here
            CollisionFlag_Crate,  // Collision flag - e.g. What is this actor ?
            (CollisionFlag_Crate | CollisionFlag_Solid | CollisionFlag_Ground | CollisionFlag_Bullet | CollisionFlag_Magic | CollisionFlag_Explosion | CollisionFlag_ClawAttack | CollisionFlag_EnemyAIProjectile),  // Collision mask - e.g. With what does this actor collide with ?
            0.0f,  // Density - determines if this character bounces
            0.0f,  // Friction - with floor and so
            0.0f)); // Restitution - makes object bounce

        pActor->LinkEndChild(CreateCycleAnimationComponent(75, true));
        pActor->LinkEndChild(CreateLootComponent(loot));
        pActor->LinkEndChild(CreateDestroyableComponent(true, "DEFAULT", { SOUND_GAME_CRATE_BREAK1, SOUND_GAME_CRATE_BREAK2 }));
        pActor->LinkEndChild(CreateHealthComponent(health, health));

        return pActor;
    }

    TiXmlElement* CreateXmlData_PowderKegActor(std::string imageSet, Point position, int32 damage, int32 zCoord)
    {
        TiXmlElement* pActor = new TiXmlElement("Actor");
        pActor->SetAttribute("Type", imageSet.c_str());

        pActor->LinkEndChild(CreatePositionComponent(position.x, position.y));
        pActor->LinkEndChild(CreateActorRenderComponent(imageSet.c_str(), zCoord));
        pActor->LinkEndChild(CreatePhysicsComponent(
            "Static",  // Type - "Dynamic", "Kinematic", "Static"
            false,      // Has foot sensor ?
            false,      // Has capsule shape ?
            true,       // Has bullet behaviour ?
            true,       // Has sensor behaviour ?
            "Crate",    // Fixture type
            position,      // Position
            Point(0, 0),   // Offset - where to move the body upon its placement
            "Rectangle",   // Body shape - "Rectangle" or "Circle"
            Point(0, 0),   // Size - Leave blank if you want size to be determined by its default image
            0.0f,          // Gravity scale - set to 0.0f if no gravity is desired
            false,          // Has any initial speed ?
            false,         // Has initial impulse ?
            Point(0, 0), // If it does, specify it here
            CollisionFlag_PowderKeg,  // Collision flag - e.g. What is this actor ?
            (CollisionFlag_Crate | CollisionFlag_Solid | CollisionFlag_Ground | CollisionFlag_Bullet | CollisionFlag_Explosion),  // Collision mask - e.g. With what does this actor collide with ?
            0.0f,  // Friction - with floor and so
            0.0f,  // Density - determines if this character bounces
            0.3f)); // Restitution - makes object bounce

        pActor->LinkEndChild(CreateAnimationComponent("/LEVEL1/ANIS/POWDERKEG/EXPLODE.ANI", true));
        pActor->LinkEndChild(CreateDestroyableComponent(true, "explode", { SOUND_LEVEL1_KEG_EXPLODE }));
        pActor->LinkEndChild(CreateHealthComponent(1, 1));
        pActor->LinkEndChild(CreateExplodeableComponent(Point(120, 120), damage));

        return pActor;
    }

    TiXmlElement* CreateXmlData_AreaDamageActor(Point position, Point size, int32 damage, CollisionFlag collisionFlag, std::string shape, Point positionOffset, std::string imageSet = "", int32 zCoord = 0)
    {
        TiXmlElement* pActor = new TiXmlElement("Actor");
        pActor->SetAttribute("Type", "AreaDamage");

        pActor->LinkEndChild(CreatePositionComponent(position.x, position.y));
        if (!imageSet.empty())
        {
            pActor->LinkEndChild(CreateActorRenderComponent(imageSet.c_str(), zCoord));
            pActor->LinkEndChild(CreateCycleAnimationComponent(75, false));
        }

        uint32 collisionMask = 0;
        if (collisionFlag == CollisionFlag_ClawAttack)
        {
            collisionMask = (CollisionFlag_Crate | CollisionFlag_DynamicActor);
        }
        else if (collisionFlag == CollisionFlag_EnemyAIAttack)
        {
            collisionMask = (CollisionFlag_Controller);
        }
        else if (collisionFlag == CollisionFlag_Explosion)
        {
            collisionMask = (CollisionFlag_Crate | CollisionFlag_PowderKeg | CollisionFlag_DynamicActor | CollisionFlag_Controller);
        }
        else
        {
            assert(false && "Unknown collision flag");
        }

        pActor->LinkEndChild(CreatePhysicsComponent(
            "Dynamic",  // Type - "Dynamic", "Kinematic", "Static"
            false,      // Has foot sensor ?
            false,      // Has capsule shape ?
            true,       // Has bullet behaviour ?
            true,       // Has sensor behaviour ?
            "Trigger",    // Fixture type
            position,      // Position
            positionOffset,   // Offset - where to move the body upon its placement
            shape,         // Body shape - "Rectangle" or "Circle"
            size,          // Size - Leave blank if you want size to be determined by its default image
            0.0f,          // Gravity scale - set to 0.0f if no gravity is desired
            false,          // Has any initial speed ?
            false,         // Has initial impulse ?
            Point(0, 0), // If it does, specify it here
            collisionFlag,  // Collision flag - e.g. What is this actor ?
            collisionMask,  // Collision mask - e.g. With what does this actor collide with ?
            0.0f,  // Friction - with floor and so
            0.0f,  // Density - determines if this character bounces
            0.0f)); // Restitution - makes object bounce*/

        
        // TODO: This does not work for some reason
        /*ActorBodyDef bodyDef;
        bodyDef.bodyType = b2_dynamicBody;
        bodyDef.makeSensor = true;
        bodyDef.collisionShape = shape;
        bodyDef.position = position;
        bodyDef.positionOffset = positionOffset;
        bodyDef.size = size;
        bodyDef.fixtureType = FixtureType_Trigger;
        bodyDef.collisionFlag = collisionFlag;
        bodyDef.collisionMask = collisionMask;
        bodyDef.gravityScale = 0.0f;

        pActor->LinkEndChild(CreatePhysicsComponent(&bodyDef));*/

        pActor->LinkEndChild(CreateTriggerComponent(-1, false, false));
        pActor->LinkEndChild(CreateAreaDamageComponent(damage));

        return pActor;
    }

    TiXmlElement* CreateXmlData_CrumblingPeg(std::string imageSet, Point position, int32 zCoord)
    {
        TiXmlElement* pActor = new TiXmlElement("Actor");
        pActor->SetAttribute("Type", imageSet.c_str());

        pActor->LinkEndChild(CreatePositionComponent(position.x, position.y));
        pActor->LinkEndChild(CreateActorRenderComponent(imageSet.c_str(), zCoord));
        pActor->LinkEndChild(CreateCycleAnimationComponent(50, true));
        pActor->LinkEndChild(CreatePhysicsComponent(
            "Static",  // Type - "Dynamic", "Kinematic", "Static"
            false,      // Has foot sensor ?
            false,      // Has capsule shape ?
            true,       // Has bullet behaviour ?
            false,       // Has sensor behaviour ?
            "Ground",    // Fixture type
            position,      // Position
            Point(0, 0),   // Offset - where to move the body upon its placement
            "Rectangle",   // Body shape - "Rectangle" or "Circle"
            Point(0, 0),          // Size - Leave blank if you want size to be determined by its default image
            0.0f,          // Gravity scale - set to 0.0f if no gravity is desired
            false,          // Has any initial speed ?
            false,         // Has initial impulse ?
            Point(0, 0), // If it does, specify it here
            CollisionFlag_Ground,  // Collision flag - e.g. What is this actor ?
            // TODO:
            CollisionFlag_Controller,  // Collision mask - e.g. With what does this actor collide with ?
            0.0f,  // Friction - with floor and so
            0.0f,  // Density - determines if this character bounces
            0.0f)); // Restitution - makes object bounce

        TiXmlElement* pCrumblingPegAIComponent = new TiXmlElement("CrumblingPegAIComponent");
        XML_ADD_TEXT_ELEMENT("FloorOffset", "10", pCrumblingPegAIComponent);
        XML_ADD_TEXT_ELEMENT("CrumbleFrameIdx", "10", pCrumblingPegAIComponent);
        pActor->LinkEndChild(pCrumblingPegAIComponent);

        return pActor;
    }

    TiXmlElement* CreateXmlData_GlitterActor(std::string glitterType, Point position, int32 zCoord)
    {
        std::string imageSet = GetImageSetFromGlitterType(glitterType);

        TiXmlElement* pActor = new TiXmlElement("Actor");
        pActor->SetAttribute("Type", imageSet.c_str());

        pActor->LinkEndChild(CreatePositionComponent(position.x, position.y));
        pActor->LinkEndChild(CreateActorRenderComponent(imageSet.c_str(), zCoord));
        pActor->LinkEndChild(CreateCycleAnimationComponent(99, false));

        return pActor;
    }

    TiXmlElement* CreateXmlData_ScorePopupActor(Point position, int score)
    {
        std::string imageSet = GetImageSetFromScoreCount(score);
        //std::string imageSet = "GAME_POINTS";

        TiXmlElement* pActor = new TiXmlElement("Actor");
        pActor->SetAttribute("Type", imageSet.c_str());

        pActor->LinkEndChild(CreatePositionComponent(position.x, position.y));
        pActor->LinkEndChild(CreateActorRenderComponent(imageSet.c_str(), 0, true, false, false, false));

        PredefinedMove move;
        move.msDuration = 650;
        move.pixelsPerSecond = Point(0, -50);
        pActor->LinkEndChild(CreatePredefinedMoveComponent(move, false));

        return pActor;
    }

    TiXmlElement* CreateXmlData_CheckpointActor(std::string imageSet, Point position, int32 zCoord, Point spawnPosition, bool isSaveCheckpoint, uint32 saveCheckpointNumber)
    {
        TiXmlElement* pActor = new TiXmlElement("Actor");
        pActor->SetAttribute("Type", imageSet.c_str());

        pActor->LinkEndChild(CreatePositionComponent(position.x, position.y));
        pActor->LinkEndChild(CreateActorRenderComponent(imageSet.c_str(), zCoord));
        pActor->LinkEndChild(CreateAnimationComponent("/GAME/ANIS/CHECKPOINT/*", true));
        pActor->LinkEndChild(CreateTriggerComponent(10, false, false));
        pActor->LinkEndChild(CreatePhysicsComponent(
            "Dynamic",  // Type - "Dynamic", "Kinematic", "Static"
            false,      // Has foot sensor ?
            false,      // Has capsule shape ?
            false,       // Has bullet behaviour ?
            false,       // Has sensor behaviour ?
            "Trigger",    // Fixture type
            position,      // Position
            Point(0, 0),   // Offset - where to move the body upon its placement
            "Rectangle",   // Body shape - "Rectangle" or "Circle"
            Point(0, 0),          // Size - Leave blank if you want size to be determined by its default image
            0.0f,          // Gravity scale - set to 0.0f if no gravity is desired
            false,          // Has any initial speed ?
            false,         // Has initial impulse ?
            Point(0, 0), // If it does, specify it here
            CollisionFlag_Checkpoint,  // Collision flag - e.g. What is this actor ?
            // TODO:
            CollisionFlag_Controller,  // Collision mask - e.g. With what does this actor collide with ?
            0.0f,  // Friction - with floor and so
            0.0f,  // Density - determines if this character bounces
            0.0f)); // Restitution - makes object bounce

        TiXmlElement* pCheckpointComponent = new TiXmlElement("CheckpointComponent");
        XML_ADD_2_PARAM_ELEMENT("SpawnPosition", "x", ToStr(spawnPosition.x).c_str(), "y", ToStr(spawnPosition.y).c_str(), pCheckpointComponent);
        XML_ADD_TEXT_ELEMENT("IsSaveCheckpoint", ToStr(isSaveCheckpoint).c_str(), pCheckpointComponent);
        XML_ADD_TEXT_ELEMENT("SaveCheckpointNumber", ToStr(saveCheckpointNumber).c_str(), pCheckpointComponent);
        pActor->LinkEndChild(pCheckpointComponent);

        return pActor;
    }

    TiXmlElement* CreateXmlData_EnemyAIActor(std::string imageSet, std::string animationSet, Point position, const std::vector<PickupType>& loot, std::string logicName, int32 zCoord, int32 minPatrolX, int32 maxPatrolX)
    {
        TiXmlElement* pActor = new TiXmlElement("Actor");
        pActor->SetAttribute("Type", logicName.c_str());

        pActor->LinkEndChild(CreatePositionComponent(position.x, position.y));
        pActor->LinkEndChild(CreateActorRenderComponent(imageSet, zCoord));
        pActor->LinkEndChild(CreateAnimationComponent(animationSet, false));
        pActor->LinkEndChild(CreateTriggerComponent(1000, false, false));
        pActor->LinkEndChild(CreateHealthComponent(10, 10));
        pActor->LinkEndChild(CreateLootComponent(loot));

        ActorBodyDef bodyDef;
        bodyDef.bodyType = b2_dynamicBody;
        bodyDef.makeSensor = false;
        bodyDef.makeCapsule = true;
        bodyDef.fixtureType = FixtureType_EnemyAI;
        //bodyDef.position = position;
        bodyDef.collisionFlag = CollisionFlag_DynamicActor;
        bodyDef.collisionMask = (CollisionFlag_Solid | CollisionFlag_Ground | CollisionFlag_Death);
        //bodyDef.collisionMask = (CollisionFlag_Solid | CollisionFlag_Ground | CollisionFlag_Death | CollisionFlag_Controller | CollisionFlag_Bullet | CollisionFlag_Magic | CollisionFlag_ClawAttack);
        //bodyDef.collisionMask = 0xFFFFF;

        if (logicName == "Soldier" || logicName == "Officer")
        {
            bodyDef.size = Point(50, 110);
        }
        else if (logicName == "Rat")
        {
            bodyDef.size = Point(40, 41);
        }

        ActorFixtureDef fixtureDef;
        fixtureDef.fixtureType = FixtureType_EnemyAI;
        fixtureDef.collisionFlag = CollisionFlag_DynamicActor;
        fixtureDef.collisionMask = (CollisionFlag_Death | CollisionFlag_Controller | CollisionFlag_Bullet | CollisionFlag_Magic | CollisionFlag_ClawAttack | CollisionFlag_Explosion);
        fixtureDef.isSensor = true;
        fixtureDef.size = Point(40, 70);
        bodyDef.fixtureList.push_back(fixtureDef);

        TiXmlElement* pEnemyAIElem = new TiXmlElement("EnemyAIComponent");
        if (logicName == "Soldier")
        {
            XML_ADD_TEXT_ELEMENT("DeathAnimation", "killfall", pEnemyAIElem);

            pActor->LinkEndChild(pEnemyAIElem);

            //=========================================================================================================
            // Patrol

            std::string walkAnimation = "fastadvance";

            std::vector<std::string> idleAnimations;
            idleAnimations.push_back("stand1");
            idleAnimations.push_back("stand");
            idleAnimations.push_back("stand2");

            pActor->LinkEndChild(CreateXmlData_PatrolState(750, 1.2, minPatrolX, maxPatrolX, walkAnimation, idleAnimations));

            //=========================================================================================================
            // Melee

            std::vector<EnemyAttackAction> meleeAttacks;

            EnemyAttackAction meleeAttackAction;
            meleeAttackAction.animation = "strike1";
            meleeAttackAction.attackAnimFrameIdx = 4;
            meleeAttackAction.attackDamageType = DamageType_MeleeAttack;
            meleeAttackAction.attackFxImageSet = "NONE";
            meleeAttackAction.attackSpawnPositionOffset = Point(-30, 0);
            meleeAttackAction.attackAreaSize = Point(90, 30);
            meleeAttackAction.damage = 10;

            meleeAttacks.push_back(meleeAttackAction);

            pActor->LinkEndChild(CreateXmlData_EnemyAttackActionState(meleeAttacks));

            //=========================================================================================================
            // Ranged

            std::vector<EnemyAttackAction> rangedAttacks;

            EnemyAttackAction rangedAttackAction;
            rangedAttackAction.animation = "strike";
            rangedAttackAction.attackAnimFrameIdx = 2;
            rangedAttackAction.attackDamageType = DamageType_Bullet;
            rangedAttackAction.attackFxImageSet = "/LEVEL1/IMAGES/MUSKETBALL/*";
            rangedAttackAction.attackSpawnPositionOffset = Point(-42, -38);
            rangedAttackAction.attackAreaSize = Point(0, 0);
            rangedAttackAction.damage = 10;

            rangedAttacks.push_back(rangedAttackAction);

            pActor->LinkEndChild(CreateXmlData_EnemyAttackActionState(rangedAttacks));


            bodyDef.fixtureList.push_back(
                CreateActorAgroRangeFixture(Point(120, 50), Point(0, 0), FixtureType_EnemyAIMeleeSensor));
            bodyDef.fixtureList.push_back(
                CreateActorAgroRangeFixture(Point(1000, 50), Point(0, -30), FixtureType_EnemyAIRangedSensor));
        }
        else if (logicName == "Officer")
        {
            XML_ADD_TEXT_ELEMENT("DeathAnimation", "fall", pEnemyAIElem);

            pActor->LinkEndChild(pEnemyAIElem);

            //=========================================================================================================
            // Patrol

            std::string walkAnimation = "fastadvance";

            std::vector<std::string> idleAnimations;
            idleAnimations.push_back("stand1");
            idleAnimations.push_back("stand2");
            idleAnimations.push_back("stand3");
            idleAnimations.push_back("stand4");
            idleAnimations.push_back("stand5");

            pActor->LinkEndChild(CreateXmlData_PatrolState(900, 1.3, minPatrolX, maxPatrolX, walkAnimation, idleAnimations));

            //=========================================================================================================
            // Melee

            std::vector<EnemyAttackAction> meleeAttacks;

            EnemyAttackAction meleeAttackAction;
            meleeAttackAction.animation = "strike";
            meleeAttackAction.attackAnimFrameIdx = 3;
            meleeAttackAction.attackDamageType = DamageType_MeleeAttack;
            meleeAttackAction.attackFxImageSet = "NONE";
            meleeAttackAction.attackSpawnPositionOffset = Point(-30, 0);
            meleeAttackAction.attackAreaSize = Point(130, 30);
            meleeAttackAction.damage = 10;

            meleeAttacks.push_back(meleeAttackAction);

            pActor->LinkEndChild(CreateXmlData_EnemyAttackActionState(meleeAttacks));


            bodyDef.fixtureList.push_back(
                CreateActorAgroRangeFixture(Point(120, 50), Point(0, 0), FixtureType_EnemyAIMeleeSensor));
        }
        else if (logicName == "Rat")
        {
            XML_ADD_TEXT_ELEMENT("DeathAnimation", "dead", pEnemyAIElem);

            pActor->LinkEndChild(pEnemyAIElem);

            //=========================================================================================================
            // Patrol

            std::string walkAnimation = "walk";

            std::vector<std::string> idleAnimations;

            pActor->LinkEndChild(CreateXmlData_PatrolState(900, 1.3, minPatrolX, maxPatrolX, walkAnimation, idleAnimations, true));

            //=========================================================================================================
            // Ranged

            std::vector<EnemyAttackAction> rangedAttacks;

            EnemyAttackAction rangedAttackAction;
            rangedAttackAction.animation = "throweastwest";
            rangedAttackAction.attackAnimFrameIdx = 2;
            rangedAttackAction.attackDamageType = DamageType_Bullet;
            rangedAttackAction.attackFxImageSet = "/LEVEL1/IMAGES/RATBOMB/*";
            rangedAttackAction.attackSpawnPositionOffset = Point(-15, 0);
            rangedAttackAction.attackAreaSize = Point(0, 0);
            rangedAttackAction.damage = 20;

            rangedAttacks.push_back(rangedAttackAction);

            pActor->LinkEndChild(CreateXmlData_EnemyAttackActionState(rangedAttacks));

            bodyDef.fixtureList.push_back(
                CreateActorAgroRangeFixture(Point(1000, 50), Point(0, 0), FixtureType_EnemyAIRangedSensor));
        }

        // Add sounds associated to given enemy
        auto soundTypeAndNamePairs = GetSoundsFromActorLogic(logicName);
        for (std::pair<std::string, std::string> soundTypeAndNamePair : soundTypeAndNamePairs)
        {
            XML_ADD_2_PARAM_ELEMENT("Sound", "SoundType", soundTypeAndNamePair.first.c_str(), 
                "SoundName", soundTypeAndNamePair.second.c_str(), pEnemyAIElem);
        }

        pActor->LinkEndChild(CreatePhysicsComponent(&bodyDef));

        return pActor;
    }

    //=====================================================================================================================
    // Public API
    //=====================================================================================================================

    StrongActorPtr CreateActorPickup(PickupType pickupType, Point position, bool isStatic)
    {
        std::string imageSet = g_PickupTypeToImageSetMap[pickupType];
        if (imageSet.empty())
        {
            LOG_ERROR("Could not get valid image set for pickup type: " + ToStr(pickupType));
            return StrongActorPtr();
        }

        std::string pickupSound = g_PickupTypeToPickupSoundMap[pickupType];
        if (pickupSound.empty())
        {
            LOG_ERROR("Could not get valid pickup sound for pickup type: " + ToStr(pickupType));
            return StrongActorPtr();
        }

        TiXmlElement* pActorXmlData = NULL;
        if (imageSet.find("_TREASURE") != std::string::npos)
        {
            pActorXmlData = CreateXmlData_TreasurePickupActor(imageSet, pickupSound, position, isStatic);
        }
        else if (imageSet.find("_CATNIPS") != std::string::npos)
        {
            pActorXmlData = CreateXmlData_PowerupPickupActor(imageSet, pickupSound, position, isStatic);
        }
        else if (imageSet.find("_AMMO") != std::string::npos ||
                 imageSet.find("_MAGIC") != std::string::npos ||
                 imageSet.find("_DYNAMITE") != std::string::npos)
        {
            pActorXmlData = CreateXmlData_AmmoPickupActor(imageSet, pickupSound, position, isStatic);
        }
        else if (imageSet.find("_HEALTH") != std::string::npos)
        {
            pActorXmlData = CreateXmlData_HealthPickupActor(imageSet, pickupSound, position, isStatic);
        }
        else
        {
            LOG_ERROR("Offending image set: " + imageSet);
            assert(false);
        }

        return CreateAndReturnActor(pActorXmlData);
    }

    StrongActorPtr CreateRenderedActor(Point position, std::string imageSet, std::string animPath, int zCoord)
    {
        TiXmlElement* pActor = new TiXmlElement("Actor");
        pActor->SetAttribute("Type", imageSet.c_str());

        pActor->LinkEndChild(CreatePositionComponent(position.x, position.y));
        pActor->LinkEndChild(CreateActorRenderComponent(imageSet, zCoord, true, false, false, false));
        if (!animPath.empty())
        {
            pActor->LinkEndChild(CreateAnimationComponent(animPath, true));
        }

        return CreateAndReturnActor(pActor);
    }

    StrongActorPtr CreatePowerupSparkleActor()
    {
        return CreateAndReturnActor(CreateXmlData_PowerupSparkleActor("GAME_SPARKLE"));
    }

    StrongActorPtr CreateClawProjectile(AmmoType ammoType, Direction direction, Point position)
    {
        return CreateAndReturnActor(CreateXmlData_ClawProjectileActor(ammoType, direction, position));
    }

    StrongActorPtr CreateProjectile(
        std::string imageSet, 
        uint32 damage, 
        DamageType damageType, 
        Direction direction, 
        Point position, 
        CollisionFlag collisionFlag, 
        uint32 collisionMask)
    {
        return CreateAndReturnActor(CreateXmlData_ProjectileActor(
            imageSet, 
            damage, 
            damageType, 
            direction, 
            position, 
            collisionFlag, 
            collisionMask));
    }

    StrongActorPtr CreateAreaDamage(Point position, Point size, int32 damage, CollisionFlag damageType, std::string shape, Point positionOffset, std::string imageSet, int32 zCoord)
    {
        return CreateAndReturnActor(CreateXmlData_AreaDamageActor(position, size, damage, damageType, shape, positionOffset, imageSet, zCoord));
    }

    StrongActorPtr CreateGlitter(std::string glitterType, Point position, int32 zCoord)
    {
        return CreateAndReturnActor(CreateXmlData_GlitterActor(glitterType, position, zCoord));
    }

    StrongActorPtr CreateScorePopupActor(Point position, int score)
    {
        return CreateAndReturnActor(CreateXmlData_ScorePopupActor(position, score));
    }

    // From XML to Struct

    ActorFixtureDef ParseActorFixtureDef(TiXmlElement* pActorFixtureDefElem)
    {
        assert(pActorFixtureDefElem != NULL);

        ActorFixtureDef fixtureDef;

        std::string fixtureTypeStr;
        SetStringIfDefined(&fixtureTypeStr, pActorFixtureDefElem->FirstChildElement("FixtureType"));
        fixtureDef.fixtureType = FixtureTypeStringToEnum(fixtureTypeStr);

        ParseValueFromXmlElem(&fixtureDef.collisionShape, pActorFixtureDefElem->FirstChildElement("CollisionShape"));
        ParseValueFromXmlElem(&fixtureDef.isSensor, pActorFixtureDefElem->FirstChildElement("IsSensor"));
        SetPointIfDefined(&fixtureDef.size, pActorFixtureDefElem->FirstChildElement("Size"), "width", "height");
        SetPointIfDefined(&fixtureDef.offset, pActorFixtureDefElem->FirstChildElement("Offset"), "x", "y");
        SetEnumIfDefined(&fixtureDef.collisionFlag, pActorFixtureDefElem->FirstChildElement("CollisionFlag"), CollisionFlag);
        ParseValueFromXmlElem(&fixtureDef.collisionMask, pActorFixtureDefElem->FirstChildElement("CollisionMask"));
        ParseValueFromXmlElem(&fixtureDef.friction, pActorFixtureDefElem->FirstChildElement("Friction"));
        ParseValueFromXmlElem(&fixtureDef.density, pActorFixtureDefElem->FirstChildElement("Density"));
        ParseValueFromXmlElem(&fixtureDef.restitution, pActorFixtureDefElem->FirstChildElement("Restitution"));

        return fixtureDef;
    }
};