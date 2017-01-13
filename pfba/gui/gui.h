//
// Created by cpasjuste on 22/11/16.
//

#ifndef _GUI_H_
#define _GUI_H_

#include <skeleton/renderer.h>
#include <skeleton/input.h>
#include "skin.h"
#include "romlist.h"
#include "config.h"
class Config;
class Option;

#define INPUT_DELAY 150

class Gui {

public:

    Gui(Renderer *rdr, Utility *util, RomList *rList, Config *cfg, Input *input);

    ~Gui();


    void Run();
    void RunRom(RomList::Rom *rom);
    int MessageBox(const char *message, const char *choice1, const char *choice2);
    void DrawBg();
    void DrawRomList();
    void DrawOptions(bool isRomCfg, std::vector<Option> *options, int start, int end);
    void DrawRomInfo(RomList::Rom *rom);
    void RunOptionMenu(bool isRomConfig = false);
    void RunStatesMenu();
    int GetButton();
    int LoadTitle(RomList::Rom *rom);
    void SetTitleLoadDelay(int delay);

    void SetPlayerInputMapping(bool isRomCfg);

    void Clear();
    void Flip();

    Renderer *GetRenderer();
    Skin *GetSkin();
    Config *GetConfig();
    Input *GetInput();

private:

    bool IsOptionHidden(Option *option);

    enum GuiMode { List = 0, CfgGui };
    GuiMode mode = List;
    Config *config = NULL;
    Renderer *renderer = NULL;
    Utility *utility = NULL;
    Skin *skin = NULL;
    Input *input = NULL;

    Texture *title = NULL;
    int title_loaded = 0;
    int title_delay = 0;

    RomList *romList = NULL;
    std::vector<RomList::Rom> roms;
    RomList::Rom *romSelected = NULL;
    void FilterRoms();

    Rect rectTitle;
    Rect rectRomList;
    Rect rectRomInfo;
    Rect rectRomPreview;

    bool quit = false;
};

#endif //_GUI_H_