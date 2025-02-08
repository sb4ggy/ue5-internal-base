#pragma once
#include "../gui/ZeroGUI.h"

void RenderText(UCanvas* canvas, FVector2D Position, std::string text, FLinearColor color) {
    std::wstring ws(text.size(), L' ');
    ws.resize(std::mbstowcs(&ws[0], text.c_str(), text.size()));
    canvas->K2_DrawText(engine_font, ws.c_str(), Position, { 1.f, 1.f }, color, false, { 0.0f, 0.0f, 0.0f, 1.f }, { 0.0f, 0.0f }, false, false, true, {0.f, 0.f, 0.f, 1.f});
}

void RenderLine(UCanvas* canvas, FVector2D Pos1, FVector2D Pos2, float thickness, FLinearColor color) {
    canvas->K2_DrawLine(Pos1, Pos2, thickness, color);
}

void RenderBox(UCanvas* canvas, FVector2D TopLeft, FVector2D DownRight, FLinearColor color, float Thickness) {
    auto h = DownRight.y - TopLeft.y;
    auto w = DownRight.x - TopLeft.x;

    auto downleft = FVector2D{ TopLeft.x, DownRight.y };
    auto topright = FVector2D{ DownRight.x, TopLeft.y };

    RenderLine(canvas, TopLeft, { TopLeft.x, TopLeft.y + h * 1 }, Thickness, color);
    RenderLine(canvas, TopLeft, { TopLeft.x + w * 1, TopLeft.y }, Thickness, color);

    RenderLine(canvas, DownRight, { DownRight.x, DownRight.y - h * 1 }, Thickness, color);
    RenderLine(canvas, DownRight, { DownRight.x - w * 1, DownRight.y }, Thickness, color);

    RenderLine(canvas, downleft, { downleft.x, downleft.y - h * 1 }, Thickness, color);
    RenderLine(canvas, downleft, { downleft.x + w * 1, DownRight.y }, Thickness, color);

    RenderLine(canvas, topright, { topright.x, topright.y + h * 1 }, Thickness, color);
    RenderLine(canvas, topright, { topright.x - w * 1, topright.y }, Thickness, color);
}