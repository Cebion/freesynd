/************************************************************************
 *                                                                      *
 *  FreeSynd - a remake of the classic Bullfrog game "Syndicate".       *
 *                                                                      *
 *   Copyright (C) 2005  Stuart Binge  <skbinge@gmail.com>              *
 *   Copyright (C) 2005  Joost Peters  <joostp@users.sourceforge.net>   *
 *   Copyright (C) 2006  Trent Waddington <qg@biodome.org>              *
 *   Copyright (C) 2006  Tarjei Knapstad <tarjei.knapstad@gmail.com>    *
 *   Copyright (C) 2013  Benoit Blancard <benblan@users.sourceforge.net>*
 *   Copyright (C) 2010  Bohdan Stelmakh <chamel@users.sourceforge.net> *
 *                                                                      *
 *    This program is free software;  you can redistribute it and / or  *
 *  modify it  under the  terms of the  GNU General  Public License as  *
 *  published by the Free Software Foundation; either version 2 of the  *
 *  License, or (at your option) any later version.                     *
 *                                                                      *
 *    This program is  distributed in the hope that it will be useful,  *
 *  but WITHOUT  ANY WARRANTY;  without even  the implied  warranty of  *
 *  MERCHANTABILITY  or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  *
 *  General Public License for more details.                            *
 *                                                                      *
 *    You can view the GNU  General Public License, online, at the GNU  *
 *  project's  web  site;  see <http://www.gnu.org/licenses/gpl.html>.  *
 *  The full text of the license is also included in the file COPYING.  *
 *                                                                      *
 ************************************************************************/

#ifndef CORE_APPCONTEXT_H_
#define CORE_APPCONTEXT_H_

#include "common.h"
#include "utils/configfile.h"

/*!
 * This class stores application level parameters.
 */
class AppContext : public Singleton < AppContext > {
public:
    /*!
     * Available language in the game.
     */
    enum FS_Lang {
        ENGLISH = 0,
        FRENCH = 1,
        ITALIAN = 2,
        GERMAN = 3
    };

    AppContext();
    ~AppContext();

    //! Reads the game config file from the given path
    bool readConfiguration(const std::string& iniPath);

    bool isFullScreen() { return fullscreen_; }

    bool isPlayIntro() { return playIntro_; }

    bool isTestFiles() { return test_files_; }

    //! Sets the intro flag to false in the config file
    void updateIntroFlag();
    //! Sets the test files flag to false in the config file
    void deactivateTestFlag();

    int32 getTimeForClick() { return time_for_click_; }

    FS_Lang currLanguage(void) {return curr_language_; }
    std::string getMessage(const std::string & id);
    void getMessage(const std::string & id, std::string & msg);

private:
    bool readLanguage(const ConfigFile& conf);

private:
    /*! True means the game will run in fullscreen. */
    bool fullscreen_;
    /*! True means the intro will be played.*/
    bool playIntro_;
    /*! Time range between mouse up and down that is treated as click,
     * if it will be longer it will be treated as dragging
    */
    int32 time_for_click_;
    /*! True means data files will be verified.*/
    bool test_files_;
    /*! Path to game config file. */
    std::string iniPath_;
    /*! Language file. */
    ConfigFile  *language_;
    FS_Lang curr_language_;
};

#define g_Ctx   AppContext::singleton()

#endif // CORE_APPCONTEXT_H_
