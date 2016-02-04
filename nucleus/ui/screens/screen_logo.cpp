/**
 * (c) 2014-2016 Alexandro Sanchez Bach. All rights reserved.
 * Released under GPL v2 license. Read LICENSE for more details.
 */

#include "screen_logo.h"
#include "nucleus/ui/ui.h"
#include "nucleus/ui/screens/list.h"
#include "nucleus/ui/widgets/list.h"
#include "nucleus/ui/transitions.h"
#include "nucleus/ui/length.h"

namespace ui {

ScreenLogo::ScreenLogo(UI* manager) : Screen(manager) {
    const auto* defaultFont = manager->fontRegular.get();

    // Centered
    body.style.alignH = ALIGN_HORIZONTAL_CENTER;
    body.style.alignV = ALIGN_VERTICAL_CENTER;

    // Create widgets
    auto* logo = new WidgetImage("logo");
    logo->manager = manager;
    logo->update(core::RES_IMAGE_NUCLEUS_LOGO);
    logo->style.width = 50_pct;
    logo->style.background = Color{1,0,1,1};

    /*auto* version = new WidgetText("version");
    version->manager = manager;
    version->update(defaultFont, 12_px, "Version v0.1.0 from 2016-04-01");
    version->style.margin.top = 10_px;
    version->style.width = 240_px;
    version->style.height = 20_px;
    version->style.background = Color{1,1,0,1};

    auto* author = new WidgetText("author");
    author->manager = manager;
    author->update(defaultFont, 20_px, "Created by Alexandro Sanchez Bach");
    author->style.margin.top = 40_px;
    author->style.width = 400_px;
    author->style.height = 30_px;
    author->style.background = Color{1,1,0,1};

    auto* license = new WidgetText("license");
    license->manager = manager;
    license->update(defaultFont, 20_px, "Licensed under GPL v2.0");
    license->style.margin.top = 10_px;
    license->style.width = 300_px;
    license->style.height = 30_px;
    license->style.background = Color{1,1,0,1};*/

    // Add widgets
    body.addElement(logo);
    /*body.addElement(version);
    body.addElement(author);
    body.addElement(license);*/
}

void ScreenLogo::update() {
    if (dtime > 2000ms) {
        //logo->style.opacity = 1.0f - transition::easeOut((dtime - 2000ms) / 1000ms);
    }
    if (dtime > 3000s) {
        if (!config.boot.empty()) {
            manager->pushScreen(std::make_unique<ScreenEmulator>(manager));
        } else {
            manager->pushScreen(std::make_unique<ScreenMain>(manager));
        }
        finished = true;
    }
}

}  // namespace ui
