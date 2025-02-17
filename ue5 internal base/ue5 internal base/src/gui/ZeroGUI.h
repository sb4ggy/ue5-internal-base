﻿#include "../sdk/sdk.h"
#include "ZeroInput.h"

extern UObject* engine_font;

wchar_t* s2wc(const char* c)
{
	const size_t cSize = strlen(c) + 1;
	wchar_t* wc = new wchar_t[cSize];
	mbstowcs(wc, c, cSize);

	return wc;
}

namespace ZeroGUI
{
	namespace Colors
	{
		FLinearColor Text{ 1.0f, 1.0f, 1.0f, 1.0f };
		FLinearColor Text_Shadow{ 0.0f, 0.0f, 0.0f, 0.0f };
		FLinearColor Text_Outline{ 0.0f, 0.0f, 0.0f, 0.30f };

		FLinearColor Window_Background{ 0.009f, 0.009f, 0.009f, 1.0f };
		FLinearColor Window_Header{ 0.10f, 0.15f, 0.84f, 1.0f };

		FLinearColor Button_Idle{ 0.10f, 0.15f, 0.84f, 1.0f };
		FLinearColor Button_Hovered{ 0.15f, 0.20f, 0.89f, 1.0f };
		FLinearColor Button_Active{ 0.20f, 0.25f, 0.94f, 1.0f };

		FLinearColor Checkbox_Idle{ 0.17f, 0.16f, 0.23f, 1.0f };
		FLinearColor Checkbox_Hovered{ 0.22f, 0.30f, 0.72f, 1.0f };
		FLinearColor Checkbox_Enabled{ 0.20f, 0.25f, 0.94f, 1.0f };

		FLinearColor Combobox_Idle{ 0.17f, 0.16f, 0.23f, 1.0f };
		FLinearColor Combobox_Hovered{ 0.17f, 0.16f, 0.23f, 1.0f };
		FLinearColor Combobox_Elements{ 0.239f, 0.42f, 0.82f, 1.0f };

		FLinearColor Slider_Idle{ 0.17f, 0.16f, 0.23f, 1.0f };
		FLinearColor Slider_Hovered{ 0.17f, 0.16f, 0.23f, 1.0f };
		FLinearColor Slider_Progress{ 0.22f, 0.30f, 0.72f, 1.0f };
		FLinearColor Slider_Button{ 0.10f, 0.15f, 0.84f, 1.0f };

		FLinearColor ColorPicker_Background{ 0.006f, 0.006f, 0.006f, 1.0f };
	}

	namespace PostRenderer
	{
		struct DrawList
		{
			int type = -1; //1 = FilledRect, 2 = TextLeft, 3 = TextCenter, 4 = Draw_Line
			FVector2D pos;
			FVector2D size;
			FLinearColor color;
			const wchar_t* name;
			bool outline;

			FVector2D from;
			FVector2D to;
			int thickness;
		};
		DrawList drawlist[128];

		void drawFilledRect(FVector2D pos, float w, float h, FLinearColor color)
		{
			for (int i = 0; i < 128; i++)
			{
				if (drawlist[i].type == -1)
				{
					drawlist[i].type = 1;
					drawlist[i].pos = pos;
					drawlist[i].size = FVector2D{ w, h };
					drawlist[i].color = color;
					return;
				}
			}
		}
		void TextLeft(const wchar_t* name, FVector2D pos, FLinearColor color, bool outline)
		{
			for (int i = 0; i < 128; i++)
			{
				if (drawlist[i].type == -1)
				{
					drawlist[i].type = 2;
					drawlist[i].name = name;
					drawlist[i].pos = pos;
					drawlist[i].outline = outline;
					drawlist[i].color = color;
					return;
				}
			}
		}
		void TextCenter(const wchar_t* name, FVector2D pos, FLinearColor color, bool outline)
		{
			for (int i = 0; i < 128; i++)
			{
				if (drawlist[i].type == -1)
				{
					drawlist[i].type = 3;
					drawlist[i].name = name;
					drawlist[i].pos = pos;
					drawlist[i].outline = outline;
					drawlist[i].color = color;
					return;
				}
			}
		}
		void Draw_Line(FVector2D from, FVector2D to, int thickness, FLinearColor color)
		{
			for (int i = 0; i < 128; i++)
			{
				if (drawlist[i].type == -1)
				{
					drawlist[i].type = 4;
					drawlist[i].from = from;
					drawlist[i].to = to;
					drawlist[i].thickness = thickness;
					drawlist[i].color = color;
					return;
				}
			}
		}
	}

	UCanvas* canvas;


	bool hover_element = false;
	FVector2D menu_pos = FVector2D{ 0, 0 };
	float offset_x = 0.0f;
	float offset_y = 0.0f;

	FVector2D first_element_pos = FVector2D{ 0, 0 };

	FVector2D last_element_pos = FVector2D{ 0, 0 };
	FVector2D last_element_size = FVector2D{ 0, 0 };

	int current_element = -1;
	FVector2D current_element_pos = FVector2D{ 0, 0 };
	FVector2D current_element_size = FVector2D{ 0, 0 };
	int elements_count = 0;

	bool sameLine = false;

	bool pushY = false;
	float pushYvalue = 0.0f;

	void SetupCanvas(UCanvas* _canvas)
	{
		canvas = _canvas;
	}

	FVector2D CursorPos()
	{
		POINT cursorPos;
		GetCursorPos(&cursorPos);
		return FVector2D{ (float)cursorPos.x, (float)cursorPos.y };
	}
	bool MouseInZone(FVector2D pos, FVector2D size)
	{
		FVector2D cursor_pos = CursorPos();

		if (cursor_pos.x > pos.x && cursor_pos.y > pos.y)
			if (cursor_pos.x < pos.x + size.x && cursor_pos.y < pos.y + size.y)
				return true;

		return false;
	}

	void Draw_Cursor(bool toogle)
	{
		if (toogle)
		{
			FVector2D cursorPos = CursorPos();
			canvas->K2_DrawLine(FVector2D{ cursorPos.x, cursorPos.y }, FVector2D{ cursorPos.x + 35, cursorPos.y + 10 }, 1, FLinearColor{ 0.30f, 0.30f, 0.80f, 1.0f });


			int x = 35;
			int y = 10;
			while (y != 30) //20 steps
			{
				x -= 1; if (x < 15) x = 15;
				y += 1; if (y > 30) y = 30;

				canvas->K2_DrawLine(FVector2D{ cursorPos.x, cursorPos.y }, FVector2D{ cursorPos.x + x, cursorPos.y + y }, 1, FLinearColor{ 0.30f, 0.30f, 0.80f, 1.0f });
			}

			canvas->K2_DrawLine(FVector2D{ cursorPos.x, cursorPos.y }, FVector2D{ cursorPos.x + 15, cursorPos.y + 30 }, 1, FLinearColor{ 0.30f, 0.30f, 0.80f, 1.0f });
			canvas->K2_DrawLine(FVector2D{ cursorPos.x + 35, cursorPos.y + 10 }, FVector2D{ cursorPos.x + 15, cursorPos.y + 30 }, 1, FLinearColor{ 0.30f, 0.30f, 0.80f, 1.0f });
		}
	}

	void SameLine()
	{
		sameLine = true;
	}
	void PushNextElementY(float y, bool from_last_element = true)
	{
		pushY = true;
		if (from_last_element)
			pushYvalue = last_element_pos.y + last_element_size.y + y;
		else
			pushYvalue = y;
	}
	void NextColumn(float x)
	{
		offset_x = x;
		PushNextElementY(first_element_pos.y, false);
	}
	void ClearFirstPos()
	{
		first_element_pos = FVector2D{ 0, 0 };
	}

	void TextLeft(const wchar_t* name, FVector2D pos, FLinearColor color, bool outline)
	{
		canvas->K2_DrawText(engine_font, name, pos, FVector2D{ 0.97f, 0.97f }, color, false, Colors::Text_Shadow, FVector2D{ pos.x + 1, pos.y + 1 }, false, true, true, Colors::Text_Outline);
	}
	void TextCenter(const wchar_t* name, FVector2D pos, FLinearColor color, bool outline)
	{
		canvas->K2_DrawText(engine_font, name, pos, FVector2D{ 0.97f, 0.97f }, color, false, Colors::Text_Shadow, FVector2D{ pos.x + 1, pos.y + 1 }, true, true, true, Colors::Text_Outline);
	}

	void GetColor(FLinearColor* color, float* r, float* g, float* b, float* a)
	{
		*r = color->r;
		*g = color->g;
		*b = color->b;
		*a = color->a;
	}
	UINT32 GetColorUINT(int r, int g, int b, int a)
	{
		UINT32 result = (BYTE(a) << 24) + (BYTE(r) << 16) + (BYTE(g) << 8) + BYTE(b);
		return result;
	}

	void Draw_Line(FVector2D from, FVector2D to, int thickness, FLinearColor color)
	{
		canvas->K2_DrawLine(FVector2D{ from.x, from.y }, FVector2D{ to.x, to.y }, thickness, color);
	}
	void drawFilledRect(FVector2D initial_pos, float w, float h, FLinearColor color)
	{
		for (float i = 0.0f; i < h; i += 1.0f)
			canvas->K2_DrawLine(FVector2D{ initial_pos.x, initial_pos.y + i }, FVector2D{ initial_pos.x + w, initial_pos.y + i }, 1.0f, color);
	}
	void DrawFilledCircle(FVector2D pos, float r, FLinearColor color)
	{
		float smooth = 0.07f;

		double PI = 3.14159265359;
		int size = (int)(2.0f * PI / smooth) + 1;

		float angle = 0.0f;
		int i = 0;

		for (; angle < 2 * PI; angle += smooth, i++)
		{
			Draw_Line(FVector2D{ pos.x, pos.y }, FVector2D{ pos.x + cosf(angle) * r, pos.y + sinf(angle) * r }, 1.0f, color);
		}
	}
	void DrawCircle(FVector2D pos, int radius, int numSides, FLinearColor Color)
	{
		float PI = 3.1415927f;

		float Step = PI * 2.0 / numSides;
		int Count = 0;
		FVector2D V[128];
		for (float a = 0; a < PI * 2.0; a += Step) {
			float X1 = radius * cos(a) + pos.x;
			float Y1 = radius * sin(a) + pos.y;
			float X2 = radius * cos(a + Step) + pos.x;
			float Y2 = radius * sin(a + Step) + pos.y;
			V[Count].x = X1;
			V[Count].y = Y1;
			V[Count + 1].x = X2;
			V[Count + 1].y = Y2;
			//Draw_Line(FVector2D{ pos.x, pos.y }, FVector2D{ X2, Y2 }, 1.0f, Color); // Points from Centre to ends of circle
			Draw_Line(FVector2D{ V[Count].x, V[Count].y }, FVector2D{ X2, Y2 }, 1.0f, Color);// Circle Around
		}
	}

	FVector2D dragPos;
	bool Window(const wchar_t* name, FVector2D* pos, FVector2D size, bool isOpen)
	{
		elements_count = 0;

		if (!isOpen)
			return false;

		bool isHovered = MouseInZone(FVector2D{ pos->x, pos->y }, size);

		//Drop last element
		if (current_element != -1 && !GetAsyncKeyState(0x1))
		{
			current_element = -1;
		}

		//Drag
		if (hover_element && GetAsyncKeyState(0x1))
		{

		}
		else if ((isHovered || dragPos.x != 0) && !hover_element)
		{
			if (Input::IsMouseClicked(0, elements_count, true))
			{
				FVector2D cursorPos = CursorPos();

				cursorPos.x -= size.x;
				cursorPos.y -= size.y;

				if (dragPos.x == 0)
				{
					dragPos.x = (cursorPos.x - pos->x);
					dragPos.y = (cursorPos.y - pos->y);
				}
				pos->x = cursorPos.x - dragPos.x;
				pos->y = cursorPos.y - dragPos.y;
			}
			else
			{
				dragPos = FVector2D{ 0, 0 };
			}
		}
		else
		{
			hover_element = false;
		}


		offset_x = 0.0f; offset_y = 0.0f;
		menu_pos = FVector2D{ pos->x, pos->y };
		first_element_pos = FVector2D{ 0, 0 };
		current_element_pos = FVector2D{ 0, 0 };
		current_element_size = FVector2D{ 0, 0 };

		//Bg
		drawFilledRect(FVector2D{ pos->x, pos->y }, size.x, size.y, Colors::Window_Background);
		//drawFilledRect(FVector2D{ pos->x, pos->y }, 122, size.y, FLinearColor{ 0.006f, 0.006f, 0.006f, 1.0f });//My tabs bg

		//Header
		drawFilledRect(FVector2D{ pos->x, pos->y }, size.x, 25.0f, Colors::Window_Header);

		offset_y += 25.0f;

		//Title
		FVector2D titlePos = FVector2D{ pos->x + size.x / 2, pos->y + 25 / 2 };
		TextCenter(name, titlePos, FLinearColor{ 1.0f, 1.0f, 1.0f, 1.0f }, false);

		return true;
	}

	void Text(const wchar_t* text, bool center = false, bool outline = false)
	{
		elements_count++;

		float size = 25;
		FVector2D padding = FVector2D{ 10, 10 };
		FVector2D pos = FVector2D{ menu_pos.x + padding.x + offset_x, menu_pos.y + padding.y + offset_y };
		if (sameLine)
		{
			pos.x = last_element_pos.x + last_element_size.x + padding.x;
			pos.y = last_element_pos.y;
		}
		if (pushY)
		{
			pos.y = pushYvalue;
			pushY = false;
			pushYvalue = 0.0f;
			offset_y = pos.y - menu_pos.y;
		}

		if (!sameLine)
			offset_y += size + padding.y;

		//Text
		FVector2D textPos = FVector2D{ pos.x + 5.0f, pos.y + size / 2 };
		if (center)
			TextCenter(text, textPos, FLinearColor{ 1.0f, 1.0f, 1.0f, 1.0f }, outline);
		else
			TextLeft(text, textPos, FLinearColor{ 1.0f, 1.0f, 1.0f, 1.0f }, outline);

		sameLine = false;
		last_element_pos = pos;
		//last_element_size = size;
		if (first_element_pos.x == 0.0f)
			first_element_pos = pos;
	}
	bool ButtonTab(const wchar_t* name, FVector2D size, bool active)
	{
		elements_count++;

		FVector2D padding = FVector2D{ 5, 10 };
		FVector2D pos = FVector2D{ menu_pos.x + padding.x + offset_x, menu_pos.y + padding.y + offset_y };
		if (sameLine)
		{
			pos.x = last_element_pos.x + last_element_size.x + padding.x;
			pos.y = last_element_pos.y;
		}
		if (pushY)
		{
			pos.y = pushYvalue;
			pushY = false;
			pushYvalue = 0.0f;
			offset_y = pos.y - menu_pos.y;
		}
		bool isHovered = MouseInZone(FVector2D{ pos.x, pos.y }, size);

		//Bg
		if (active)
		{
			drawFilledRect(FVector2D{ pos.x, pos.y }, size.x, size.y, Colors::Button_Active);
		}
		else if (isHovered)
		{
			drawFilledRect(FVector2D{ pos.x, pos.y }, size.x, size.y, Colors::Button_Hovered);
			hover_element = true;
		}
		else
		{
			drawFilledRect(FVector2D{ pos.x, pos.y }, size.x, size.y, Colors::Button_Idle);
		}

		if (!sameLine)
			offset_y += size.y + padding.y;

		//Text
		FVector2D textPos = FVector2D{ pos.x + size.x / 2, pos.y + size.y / 2 };
		TextCenter(name, textPos, FLinearColor{ 1.0f, 1.0f, 1.0f, 1.0f }, false);


		sameLine = false;
		last_element_pos = pos;
		last_element_size = size;
		if (first_element_pos.x == 0.0f)
			first_element_pos = pos;

		if (isHovered && Input::IsMouseClicked(0, elements_count, false))
			return true;

		return false;
	}
	bool Button(const wchar_t* name, FVector2D size)
	{
		elements_count++;

		FVector2D padding = FVector2D{ 5, 10 };
		FVector2D pos = FVector2D{ menu_pos.x + padding.x + offset_x, menu_pos.y + padding.y + offset_y };
		if (sameLine)
		{
			pos.x = last_element_pos.x + last_element_size.x + padding.x;
			pos.y = last_element_pos.y;
		}
		if (pushY)
		{
			pos.y = pushYvalue;
			pushY = false;
			pushYvalue = 0.0f;
			offset_y = pos.y - menu_pos.y;
		}
		bool isHovered = MouseInZone(FVector2D{ pos.x, pos.y }, size);

		//Bg
		if (isHovered)
		{
			drawFilledRect(FVector2D{ pos.x, pos.y }, size.x, size.y, Colors::Button_Hovered);
			hover_element = true;
		}
		else
		{
			drawFilledRect(FVector2D{ pos.x, pos.y }, size.x, size.y, Colors::Button_Idle);
		}

		if (!sameLine)
			offset_y += size.y + padding.y;

		//Text
		FVector2D textPos = FVector2D{ pos.x + size.x / 2, pos.y + size.y / 2 };
		//if (!TextOverlapedFromActiveElement(textPos))
		TextCenter(name, textPos, FLinearColor{ 1.0f, 1.0f, 1.0f, 1.0f }, false);


		sameLine = false;
		last_element_pos = pos;
		last_element_size = size;
		if (first_element_pos.x == 0.0f)
			first_element_pos = pos;

		if (isHovered && Input::IsMouseClicked(0, elements_count, false))
			return true;

		return false;
	}
	void Checkbox(const wchar_t* name, bool* value)
	{
		elements_count++;

		float size = 18;
		FVector2D padding = FVector2D{ 10, 10 };
		FVector2D pos = FVector2D{ menu_pos.x + padding.x + offset_x, menu_pos.y + padding.y + offset_y };
		if (sameLine)
		{
			pos.x = last_element_pos.x + last_element_size.x + padding.x;
			pos.y = last_element_pos.y;
		}
		if (pushY)
		{
			pos.y = pushYvalue;
			pushY = false;
			pushYvalue = 0.0f;
			offset_y = pos.y - menu_pos.y;
		}
		bool isHovered = MouseInZone(FVector2D{ pos.x, pos.y }, FVector2D{ size, size });

		//Bg
		if (isHovered)
		{
			drawFilledRect(FVector2D{ pos.x, pos.y }, size, size, Colors::Checkbox_Hovered);
			hover_element = true;
		}
		else
		{
			drawFilledRect(FVector2D{ pos.x, pos.y }, size, size, Colors::Checkbox_Idle);
		}

		if (!sameLine)
			offset_y += size + padding.y;

		if (*value)
		{
			drawFilledRect(FVector2D{ pos.x + 3, pos.y + 3 }, size - 6, size - 6, Colors::Checkbox_Enabled);
			//drawFilledRect(FVector2D{ pos.x + 9, pos.y + 9 }, size - 18, size - 18, Colors::Checkbox_Hovered);
		}



		//Text
		FVector2D textPos = FVector2D{ pos.x + size + 5.0f, pos.y + size / 2 };
		//if (!TextOverlapedFromActiveElement(textPos))
		TextLeft(name, textPos, FLinearColor{ 1.0f, 1.0f, 1.0f, 1.0f }, false);


		sameLine = false;
		last_element_pos = pos;
		//last_element_size = size;
		if (first_element_pos.x == 0.0f)
			first_element_pos = pos;

		if (isHovered && Input::IsMouseClicked(0, elements_count, false))
			*value = !*value;
	}
	void SliderInt(const wchar_t* name, int* value, int min, int max)
	{
		elements_count++;

		FVector2D size = FVector2D{ 240, 50 };
		FVector2D slider_size = FVector2D{ 200, 10 };
		FVector2D padding = FVector2D{ 10, 15 };
		FVector2D pos = FVector2D{ menu_pos.x + padding.x + offset_x, menu_pos.y + padding.y + offset_y };
		if (sameLine)
		{
			pos.x = last_element_pos.x + last_element_size.x + padding.x;
			pos.y = last_element_pos.y;
		}
		if (pushY)
		{
			pos.y = pushYvalue;
			pushY = false;
			pushYvalue = 0.0f;
			offset_y = pos.y - menu_pos.y;
		}
		bool isHovered = MouseInZone(FVector2D{ pos.x, pos.y + slider_size.y + padding.y }, slider_size);

		if (!sameLine)
			offset_y += size.y + padding.y;

		//Bg
		if (isHovered || current_element == elements_count)
		{
			//Drag
			if (Input::IsMouseClicked(0, elements_count, true))
			{
				current_element = elements_count;

				FVector2D cursorPos = CursorPos();
				*value = ((cursorPos.x - pos.x) * ((max - min) / slider_size.x)) + min;
				if (*value < min) *value = min;
				if (*value > max) *value = max;
			}

			drawFilledRect(FVector2D{ pos.x, pos.y + slider_size.y + padding.y }, slider_size.x, slider_size.y, Colors::Slider_Hovered);
			drawFilledRect(FVector2D{ pos.x, pos.y + slider_size.y + padding.y + 5.0f }, 5.0f, 5.0f, Colors::Slider_Progress);

			hover_element = true;
		}
		else
		{
			drawFilledRect(FVector2D{ pos.x, pos.y + slider_size.y + padding.y }, slider_size.x, slider_size.y, Colors::Slider_Idle);
			drawFilledRect(FVector2D{ pos.x, pos.y + slider_size.y + padding.y + 5.0f }, 5.0f, 5.0f, Colors::Slider_Progress);
		}


		//Value
		float oneP = slider_size.x / (max - min);
		drawFilledRect(FVector2D{ pos.x, pos.y + slider_size.y + padding.y }, oneP * (*value - min), slider_size.y, Colors::Slider_Progress);
		//drawFilledRect(FVector2D{ pos.x + oneP * (*value - min) - 10.0f, pos.y + slider_size.y - 5.0f + padding.y }, 20.0f, 20.0f, Colors::Slider_Button);
		DrawFilledCircle(FVector2D{ pos.x + oneP * (*value - min), pos.y + slider_size.y + 3.3f + padding.y }, 10.0f, Colors::Slider_Button);
		DrawFilledCircle(FVector2D{ pos.x + oneP * (*value - min), pos.y + slider_size.y + 3.3f + padding.y }, 5.0f, Colors::Slider_Progress);

		wchar_t buffer[32];
		swprintf_s(buffer, 32, L"%i", *value);
		FVector2D valuePos = FVector2D{ pos.x + oneP * (*value - min), pos.y + slider_size.y + 25 + padding.y };
		TextCenter(buffer, valuePos, FLinearColor{ 1.0f, 1.0f, 1.0f, 1.0f }, false);

		//Text
		FVector2D textPos = FVector2D{ pos.x + 5, pos.y + 10 };
		TextLeft(name, textPos, FLinearColor{ 1.0f, 1.0f, 1.0f, 1.0f }, false);


		sameLine = false;
		last_element_pos = pos;
		last_element_size = size;
		if (first_element_pos.x == 0.0f)
			first_element_pos = pos;
	}
	void SliderFloat(const wchar_t* name, float* value, float min, float max, const char* format = "%.0f")
	{
		elements_count++;

		FVector2D size = FVector2D{ 210, 40 };
		FVector2D slider_size = FVector2D{ 170, 7 };
		FVector2D adjust_zone = FVector2D{ 0, 20 };
		FVector2D padding = FVector2D{ 10, 15 };
		FVector2D pos = FVector2D{ menu_pos.x + padding.x + offset_x, menu_pos.y + padding.y + offset_y };
		if (sameLine)
		{
			pos.x = last_element_pos.x + last_element_size.x + padding.x;
			pos.y = last_element_pos.y;
		}
		if (pushY)
		{
			pos.y = pushYvalue;
			pushY = false;
			pushYvalue = 0.0f;
			offset_y = pos.y - menu_pos.y;
		}
		bool isHovered = MouseInZone(FVector2D{ pos.x, pos.y + slider_size.y + padding.y - adjust_zone.y }, FVector2D{ slider_size.x, slider_size.y + adjust_zone.y * 1.5f });

		if (!sameLine)
			offset_y += size.y + padding.y;

		//Bg
		if (isHovered || current_element == elements_count)
		{
			//Drag
			if (Input::IsMouseClicked(0, elements_count, true))
			{
				current_element = elements_count;

				FVector2D cursorPos = CursorPos();
				*value = ((cursorPos.x - pos.x) * ((max - min) / slider_size.x)) + min;
				if (*value < min) *value = min;
				if (*value > max) *value = max;
			}

			drawFilledRect(FVector2D{ pos.x, pos.y + slider_size.y + padding.y }, slider_size.x, slider_size.y, Colors::Slider_Hovered);
			DrawFilledCircle(FVector2D{ pos.x, pos.y + padding.y + 9.3f }, 3.1f, Colors::Slider_Progress);
			DrawFilledCircle(FVector2D{ pos.x + slider_size.x, pos.y + padding.y + 9.3f }, 3.1f, Colors::Slider_Hovered);

			hover_element = true;
		}
		else
		{
			drawFilledRect(FVector2D{ pos.x, pos.y + slider_size.y + padding.y }, slider_size.x, slider_size.y, Colors::Slider_Idle);
			DrawFilledCircle(FVector2D{ pos.x, pos.y + padding.y + 9.3f }, 3.1f, Colors::Slider_Progress);
			DrawFilledCircle(FVector2D{ pos.x + slider_size.x, pos.y + padding.y + 9.3f }, 3.1f, Colors::Slider_Idle);
		}


		//Text
		FVector2D textPos = FVector2D{ pos.x, pos.y + 5 };
		TextLeft(name, textPos, Colors::Text, false);

		//Value
		float oneP = slider_size.x / (max - min);
		drawFilledRect(FVector2D{ pos.x, pos.y + slider_size.y + padding.y }, oneP * (*value - min), slider_size.y, Colors::Slider_Progress);
		DrawFilledCircle(FVector2D{ pos.x + oneP * (*value - min), pos.y + slider_size.y + 2.66f + padding.y }, 8.0f, Colors::Slider_Button);
		DrawFilledCircle(FVector2D{ pos.x + oneP * (*value - min), pos.y + slider_size.y + 2.66f + padding.y }, 4.0f, Colors::Slider_Progress);

		char buffer[32];
		sprintf_s(buffer, format, *value);
		wchar_t wbuffer[32];
		mbstowcs(wbuffer, buffer, 32);

		FVector2D valuePos = FVector2D{ pos.x + oneP * (*value - min), pos.y + slider_size.y + 20 + padding.y };
		TextCenter(wbuffer, valuePos, Colors::Text, false);


		sameLine = false;
		last_element_pos = pos;
		last_element_size = size;
		if (first_element_pos.x == 0.0f)
			first_element_pos = pos;
	}



	bool checkbox_enabled[256];
	void Combobox(const wchar_t* name, FVector2D size, int* value, const char* arg, ...)
	{
		elements_count++;

		FVector2D padding = FVector2D{ 5, 10 };
		FVector2D pos = FVector2D{ menu_pos.x + padding.x + offset_x, menu_pos.y + padding.y + offset_y };
		if (sameLine)
		{
			pos.x = last_element_pos.x + last_element_size.x + padding.x;
			pos.y = last_element_pos.y;
		}
		if (pushY)
		{
			pos.y = pushYvalue;
			pushY = false;
			pushYvalue = 0.0f;
			offset_y = pos.y - menu_pos.y;
		}
		bool isHovered = MouseInZone(FVector2D{ pos.x, pos.y }, size);

		//Bg
		if (isHovered || checkbox_enabled[elements_count])
		{
			drawFilledRect(FVector2D{ pos.x, pos.y }, size.x, size.y, Colors::Combobox_Hovered);

			hover_element = true;
		}
		else
		{
			drawFilledRect(FVector2D{ pos.x, pos.y }, size.x, size.y, Colors::Combobox_Idle);
		}

		if (!sameLine)
			offset_y += size.y + padding.y;

		//Text
		FVector2D textPos = FVector2D{ pos.x + size.x + 5.0f, pos.y + size.y / 2 };
		TextLeft(name, textPos, FLinearColor{ 1.0f, 1.0f, 1.0f, 1.0f }, false);

		//Elements
		bool isHovered2 = false;
		FVector2D element_pos = pos;
		int num = 0;

		if (checkbox_enabled[elements_count])
		{
			current_element_size.x = element_pos.x - 5.0f;
			current_element_size.y = element_pos.y - 5.0f;
		}
		va_list arguments;
		for (va_start(arguments, arg); arg != NULL; arg = va_arg(arguments, const char*))
		{
			//Selected Element
			if (num == *value)
			{
				FVector2D _textPos = FVector2D{ pos.x + size.x / 2, pos.y + size.y / 2 };
				TextCenter((const wchar_t*)arg, _textPos, FLinearColor{ 1.0f, 1.0f, 1.0f, 1.0f }, false);
			}

			if (checkbox_enabled[elements_count])
			{
				element_pos.y += 25.0f;

				isHovered2 = MouseInZone(FVector2D{ element_pos.x, element_pos.y }, FVector2D{ size.x, 25.0f });
				if (isHovered2)
				{
					hover_element = true;
					PostRenderer::drawFilledRect(FVector2D{ element_pos.x, element_pos.y }, size.x, 25.0f, Colors::Combobox_Hovered);

					//Click
					if (Input::IsMouseClicked(0, elements_count, false))
					{
						*value = num;
						checkbox_enabled[elements_count] = false;
					}
				}
				else
				{
					PostRenderer::drawFilledRect(FVector2D{ element_pos.x, element_pos.y }, size.x, 25.0f, Colors::Combobox_Idle);
				}

				PostRenderer::TextLeft((const wchar_t*)arg, FVector2D{ element_pos.x + 5.0f, element_pos.y + 15.0f }, FLinearColor{ 1.0f, 1.0f, 1.0f, 1.0f }, false);
			}
			num++;
		}
		va_end(arguments);
		if (checkbox_enabled[elements_count])
		{
			current_element_size.x = element_pos.x + 5.0f;
			current_element_size.y = element_pos.y + 5.0f;
		}


		sameLine = false;
		last_element_pos = pos;
		last_element_size = size;
		if (first_element_pos.x == 0.0f)
			first_element_pos = pos;

		if (isHovered && Input::IsMouseClicked(0, elements_count, false))
		{
			checkbox_enabled[elements_count] = !checkbox_enabled[elements_count];
		}
		if (!isHovered && !isHovered2 && Input::IsMouseClicked(0, elements_count, false))
		{
			checkbox_enabled[elements_count] = false;
		}
	}

	int active_hotkey = -1;
	bool already_pressed = false;
	std::string VirtualKeyCodeToString(UCHAR virtualKey)
	{
		UINT scanCode = MapVirtualKey(virtualKey, MAPVK_VK_TO_VSC);

		if (virtualKey == VK_LBUTTON)
		{
			return ("MOUSE0");
		}
		if (virtualKey == VK_RBUTTON)
		{
			return ("MOUSE1");
		}
		if (virtualKey == VK_MBUTTON)
		{
			return ("MBUTTON");
		}
		if (virtualKey == VK_XBUTTON1)
		{
			return ("XBUTTON1");
		}
		if (virtualKey == VK_XBUTTON2)
		{
			return ("XBUTTON2");
		}

		CHAR szName[128];
		int result = 0;
		switch (virtualKey)
		{
		case VK_LEFT: case VK_UP: case VK_RIGHT: case VK_DOWN:
		case VK_RCONTROL: case VK_RMENU:
		case VK_LWIN: case VK_RWIN: case VK_APPS:
		case VK_PRIOR: case VK_NEXT:
		case VK_END: case VK_HOME:
		case VK_INSERT: case VK_DELETE:
		case VK_DIVIDE:
		case VK_NUMLOCK:
			scanCode |= KF_EXTENDED;
		default:
			result = GetKeyNameTextA(scanCode << 16, szName, 128);
		}

		return szName;
	}
	void Hotkey(char* name, FVector2D size, int* key)
	{
		elements_count++;

		FVector2D padding = FVector2D{ 5, 10 };
		FVector2D pos = FVector2D{ menu_pos.x + padding.x + offset_x, menu_pos.y + padding.y + offset_y };
		if (sameLine)
		{
			pos.x = last_element_pos.x + last_element_size.x + padding.x;
			pos.y = last_element_pos.y + (last_element_size.y / 2) - size.y / 2;
		}
		if (pushY)
		{
			pos.y = pushYvalue;
			pushY = false;
			pushYvalue = 0.0f;
			offset_y = pos.y - menu_pos.y;
		}
		bool isHovered = MouseInZone(FVector2D{ pos.x, pos.y }, size);

		//Bg
		if (isHovered)
		{
			drawFilledRect(FVector2D{ pos.x, pos.y }, size.x, size.y, Colors::Button_Hovered);
			hover_element = true;
		}
		else
		{
			drawFilledRect(FVector2D{ pos.x, pos.y }, size.x, size.y, Colors::Button_Idle);
		}

		if (!sameLine)
			offset_y += size.y + padding.y;

		if (active_hotkey == elements_count)
		{
			//Text
			FVector2D textPos = FVector2D{ pos.x + size.x / 2, pos.y + size.y / 2 };
			TextCenter(L"[Press Key]", textPos, FLinearColor{ 1.0f, 1.0f, 1.0f, 1.0f }, false);

			if (!ZeroGUI::Input::IsAnyMouseDown())
			{
				already_pressed = false;
			}

			if (!already_pressed)
			{
				for (int code = 0; code < 255; code++)
				{
					if (GetAsyncKeyState(code))
					{
						*key = code;
						active_hotkey = -1;
					}
				}
			}
		}
		else
		{
			//Text
			FVector2D textPos = FVector2D{ pos.x + size.x / 2, pos.y + size.y / 2 };
			TextCenter((const wchar_t*)VirtualKeyCodeToString(*key).c_str(), textPos, FLinearColor{ 1.0f, 1.0f, 1.0f, 1.0f }, false);

			if (isHovered)
			{
				if (Input::IsMouseClicked(0, elements_count, false))
				{
					already_pressed = true;
					active_hotkey = elements_count;

					//Queue Fix
					for (int code = 0; code < 255; code++)
						if (GetAsyncKeyState(code)) {}
				}
			}
			else
			{
				if (Input::IsMouseClicked(0, elements_count, false))
				{
					active_hotkey = -1;
				}
			}
		}


		sameLine = false;
		last_element_pos = pos;
		last_element_size = size;
		if (first_element_pos.x == 0.0f)
			first_element_pos = pos;
	}

	int active_picker = -1;
	FLinearColor saved_color;
	bool ColorPixel(FVector2D pos, FVector2D size, FLinearColor* original, FLinearColor color)
	{
		PostRenderer::drawFilledRect(FVector2D{ pos.x, pos.y }, size.x, size.y, color);

		//Выбранный цвет
		if (original->r == color.r && original->g == color.g && original->b == color.b)
		{
			PostRenderer::Draw_Line(FVector2D{ pos.x, pos.y }, FVector2D{ pos.x + size.x - 1, pos.y }, 1.0f, FLinearColor{ 0.0f, 0.0f, 0.0f, 1.0f });
			PostRenderer::Draw_Line(FVector2D{ pos.x, pos.y + size.y - 1 }, FVector2D{ pos.x + size.x - 1, pos.y + size.y - 1 }, 1.0f, FLinearColor{ 0.0f, 0.0f, 0.0f, 1.0f });
			PostRenderer::Draw_Line(FVector2D{ pos.x, pos.y }, FVector2D{ pos.x, pos.y + size.y - 1 }, 1.0f, FLinearColor{ 0.0f, 0.0f, 0.0f, 1.0f });
			PostRenderer::Draw_Line(FVector2D{ pos.x + size.x - 1, pos.y }, FVector2D{ pos.x + size.x - 1, pos.y + size.y - 1 }, 1.0f, FLinearColor{ 0.0f, 0.0f, 0.0f, 1.0f });
		}

		//Смена цвета
		bool isHovered = MouseInZone(FVector2D{ pos.x, pos.y }, size);
		if (isHovered)
		{
			if (Input::IsMouseClicked(0, elements_count, false))
				*original = color;
		}

		return true;
	}
	void ColorPicker(const wchar_t* name, FLinearColor* color)
	{
		elements_count++;

		float size = 25;
		FVector2D padding = FVector2D{ 10, 10 };
		FVector2D pos = FVector2D{ menu_pos.x + padding.x + offset_x, menu_pos.y + padding.y + offset_y };
		if (sameLine)
		{
			pos.x = last_element_pos.x + last_element_size.x + padding.x;
			pos.y = last_element_pos.y;
		}
		if (pushY)
		{
			pos.y = pushYvalue;
			pushY = false;
			pushYvalue = 0.0f;
			offset_y = pos.y - menu_pos.y;
		}
		bool isHovered = MouseInZone(FVector2D{ pos.x, pos.y }, FVector2D{ size, size });

		if (!sameLine)
			offset_y += size + padding.y;

		if (active_picker == elements_count)
		{
			hover_element = true;

			float sizePickerX = 250;
			float sizePickerY = 250;
			bool isHoveredPicker = MouseInZone(FVector2D{ pos.x, pos.y }, FVector2D{ sizePickerX, sizePickerY - 60 });

			//Background
			PostRenderer::drawFilledRect(FVector2D{ pos.x, pos.y }, sizePickerX, sizePickerY - 65, Colors::ColorPicker_Background);

			//float pixedSize = sizePickerY / pixels;
			//FLinearColor temp_color{1.0f, 1.0f, 1.0f, 1.0f};
			//float iterator = 0.0f;
			//
			//for (int y = 0; y < pixels; y++)
			//{
			//	for (int x = 0; x < pixels; x++)
			//	{
			//		ColorPixel(FVector2D{ pos.x + pixedSize * x, pos.y + pixedSize * y }, pixedSize, color, temp_color);
			//		temp_color.R -= (1.0f - saved_color.R) / pixels;
			//		temp_color.G -= (1.0f - saved_color.G) / pixels;
			//		temp_color.B -= (1.0f - saved_color.B) / pixels;
			//	}
			//	
			//	iterator += 1.0f / pixels;
			//	temp_color = FLinearColor{ 1.0f - iterator, 1.0f - iterator, 1.0f - iterator, 1.0f };
			//}

			FVector2D pixelSize = FVector2D{ sizePickerX / 12, sizePickerY / 12 };

			//0
			{
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 0, pos.y + pixelSize.y * 0 }, pixelSize, color, FLinearColor{ 174 / 255.f, 235 / 255.f, 253 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 0, pos.y + pixelSize.y * 1 }, pixelSize, color, FLinearColor{ 136 / 255.f, 225 / 255.f, 251 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 0, pos.y + pixelSize.y * 2 }, pixelSize, color, FLinearColor{ 108 / 255.f, 213 / 255.f, 250 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 0, pos.y + pixelSize.y * 3 }, pixelSize, color, FLinearColor{ 89 / 255.f, 175 / 255.f, 213 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 0, pos.y + pixelSize.y * 4 }, pixelSize, color, FLinearColor{ 76 / 255.f, 151 / 255.f, 177 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 0, pos.y + pixelSize.y * 5 }, pixelSize, color, FLinearColor{ 60 / 255.f, 118 / 255.f, 140 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 0, pos.y + pixelSize.y * 6 }, pixelSize, color, FLinearColor{ 43 / 255.f, 85 / 255.f, 100 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 0, pos.y + pixelSize.y * 7 }, pixelSize, color, FLinearColor{ 32 / 255.f, 62 / 255.f, 74 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 0, pos.y + pixelSize.y * 8 }, pixelSize, color, FLinearColor{ 255 / 255.f, 255 / 255.f, 255 / 255.f, 1.0f });
			}
			//1
			{
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 1, pos.y + pixelSize.y * 0 }, pixelSize, color, FLinearColor{ 175 / 255.f, 205 / 255.f, 252 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 1, pos.y + pixelSize.y * 1 }, pixelSize, color, FLinearColor{ 132 / 255.f, 179 / 255.f, 252 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 1, pos.y + pixelSize.y * 2 }, pixelSize, color, FLinearColor{ 90 / 255.f, 152 / 255.f, 250 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 1, pos.y + pixelSize.y * 3 }, pixelSize, color, FLinearColor{ 55 / 255.f, 120 / 255.f, 250 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 1, pos.y + pixelSize.y * 4 }, pixelSize, color, FLinearColor{ 49 / 255.f, 105 / 255.f, 209 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 1, pos.y + pixelSize.y * 5 }, pixelSize, color, FLinearColor{ 38 / 255.f, 83 / 255.f, 165 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 1, pos.y + pixelSize.y * 6 }, pixelSize, color, FLinearColor{ 28 / 255.f, 61 / 255.f, 120 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 1, pos.y + pixelSize.y * 7 }, pixelSize, color, FLinearColor{ 20 / 255.f, 43 / 255.f, 86 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 1, pos.y + pixelSize.y * 8 }, pixelSize, color, FLinearColor{ 247 / 255.f, 247 / 255.f, 247 / 255.f, 1.0f });
			}
			//2
			{
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 2, pos.y + pixelSize.y * 0 }, pixelSize, color, FLinearColor{ 153 / 255.f, 139 / 255.f, 250 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 2, pos.y + pixelSize.y * 1 }, pixelSize, color, FLinearColor{ 101 / 255.f, 79 / 255.f, 249 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 2, pos.y + pixelSize.y * 2 }, pixelSize, color, FLinearColor{ 64 / 255.f, 50 / 255.f, 230 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 2, pos.y + pixelSize.y * 3 }, pixelSize, color, FLinearColor{ 54 / 255.f, 38 / 255.f, 175 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 2, pos.y + pixelSize.y * 4 }, pixelSize, color, FLinearColor{ 39 / 255.f, 31 / 255.f, 144 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 2, pos.y + pixelSize.y * 5 }, pixelSize, color, FLinearColor{ 32 / 255.f, 25 / 255.f, 116 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 2, pos.y + pixelSize.y * 6 }, pixelSize, color, FLinearColor{ 21 / 255.f, 18 / 255.f, 82 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 2, pos.y + pixelSize.y * 7 }, pixelSize, color, FLinearColor{ 16 / 255.f, 13 / 255.f, 61 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 2, pos.y + pixelSize.y * 8 }, pixelSize, color, FLinearColor{ 228 / 255.f, 228 / 255.f, 228 / 255.f, 1.0f });
			}
			//3
			{
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 3, pos.y + pixelSize.y * 0 }, pixelSize, color, FLinearColor{ 194 / 255.f, 144 / 255.f, 251 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 3, pos.y + pixelSize.y * 1 }, pixelSize, color, FLinearColor{ 165 / 255.f, 87 / 255.f, 249 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 3, pos.y + pixelSize.y * 2 }, pixelSize, color, FLinearColor{ 142 / 255.f, 57 / 255.f, 239 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 3, pos.y + pixelSize.y * 3 }, pixelSize, color, FLinearColor{ 116 / 255.f, 45 / 255.f, 184 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 3, pos.y + pixelSize.y * 4 }, pixelSize, color, FLinearColor{ 92 / 255.f, 37 / 255.f, 154 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 3, pos.y + pixelSize.y * 5 }, pixelSize, color, FLinearColor{ 73 / 255.f, 29 / 255.f, 121 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 3, pos.y + pixelSize.y * 6 }, pixelSize, color, FLinearColor{ 53 / 255.f, 21 / 255.f, 88 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 3, pos.y + pixelSize.y * 7 }, pixelSize, color, FLinearColor{ 37 / 255.f, 15 / 255.f, 63 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 3, pos.y + pixelSize.y * 8 }, pixelSize, color, FLinearColor{ 203 / 255.f, 203 / 255.f, 203 / 255.f, 1.0f });
			}
			//4
			{
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 4, pos.y + pixelSize.y * 0 }, pixelSize, color, FLinearColor{ 224 / 255.f, 162 / 255.f, 197 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 4, pos.y + pixelSize.y * 1 }, pixelSize, color, FLinearColor{ 210 / 255.f, 112 / 255.f, 166 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 4, pos.y + pixelSize.y * 2 }, pixelSize, color, FLinearColor{ 199 / 255.f, 62 / 255.f, 135 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 4, pos.y + pixelSize.y * 3 }, pixelSize, color, FLinearColor{ 159 / 255.f, 49 / 255.f, 105 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 4, pos.y + pixelSize.y * 4 }, pixelSize, color, FLinearColor{ 132 / 255.f, 41 / 255.f, 89 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 4, pos.y + pixelSize.y * 5 }, pixelSize, color, FLinearColor{ 104 / 255.f, 32 / 255.f, 71 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 4, pos.y + pixelSize.y * 6 }, pixelSize, color, FLinearColor{ 75 / 255.f, 24 / 255.f, 51 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 4, pos.y + pixelSize.y * 7 }, pixelSize, color, FLinearColor{ 54 / 255.f, 14 / 255.f, 36 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 4, pos.y + pixelSize.y * 8 }, pixelSize, color, FLinearColor{ 175 / 255.f, 175 / 255.f, 175 / 255.f, 1.0f });
			}
			//5
			{
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 5, pos.y + pixelSize.y * 0 }, pixelSize, color, FLinearColor{ 235 / 255.f, 175 / 255.f, 176 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 5, pos.y + pixelSize.y * 1 }, pixelSize, color, FLinearColor{ 227 / 255.f, 133 / 255.f, 135 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 5, pos.y + pixelSize.y * 2 }, pixelSize, color, FLinearColor{ 219 / 255.f, 87 / 255.f, 88 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 5, pos.y + pixelSize.y * 3 }, pixelSize, color, FLinearColor{ 215 / 255.f, 50 / 255.f, 36 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 5, pos.y + pixelSize.y * 4 }, pixelSize, color, FLinearColor{ 187 / 255.f, 25 / 255.f, 7 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 5, pos.y + pixelSize.y * 5 }, pixelSize, color, FLinearColor{ 149 / 255.f, 20 / 255.f, 6 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 5, pos.y + pixelSize.y * 6 }, pixelSize, color, FLinearColor{ 107 / 255.f, 14 / 255.f, 4 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 5, pos.y + pixelSize.y * 7 }, pixelSize, color, FLinearColor{ 77 / 255.f, 9 / 255.f, 3 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 5, pos.y + pixelSize.y * 8 }, pixelSize, color, FLinearColor{ 144 / 255.f, 144 / 255.f, 144 / 255.f, 1.0f });
			}
			//6
			{
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 6, pos.y + pixelSize.y * 0 }, pixelSize, color, FLinearColor{ 241 / 255.f, 187 / 255.f, 171 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 6, pos.y + pixelSize.y * 1 }, pixelSize, color, FLinearColor{ 234 / 255.f, 151 / 255.f, 126 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 6, pos.y + pixelSize.y * 2 }, pixelSize, color, FLinearColor{ 229 / 255.f, 115 / 255.f, 76 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 6, pos.y + pixelSize.y * 3 }, pixelSize, color, FLinearColor{ 227 / 255.f, 82 / 255.f, 24 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 6, pos.y + pixelSize.y * 4 }, pixelSize, color, FLinearColor{ 190 / 255.f, 61 / 255.f, 15 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 6, pos.y + pixelSize.y * 5 }, pixelSize, color, FLinearColor{ 150 / 255.f, 48 / 255.f, 12 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 6, pos.y + pixelSize.y * 6 }, pixelSize, color, FLinearColor{ 107 / 255.f, 34 / 255.f, 8 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 6, pos.y + pixelSize.y * 7 }, pixelSize, color, FLinearColor{ 79 / 255.f, 25 / 255.f, 6 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 6, pos.y + pixelSize.y * 8 }, pixelSize, color, FLinearColor{ 113 / 255.f, 113 / 255.f, 113 / 255.f, 1.0f });
			}
			//7
			{
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 7, pos.y + pixelSize.y * 0 }, pixelSize, color, FLinearColor{ 245 / 255.f, 207 / 255.f, 169 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 7, pos.y + pixelSize.y * 1 }, pixelSize, color, FLinearColor{ 240 / 255.f, 183 / 255.f, 122 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 7, pos.y + pixelSize.y * 2 }, pixelSize, color, FLinearColor{ 236 / 255.f, 159 / 255.f, 74 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 7, pos.y + pixelSize.y * 3 }, pixelSize, color, FLinearColor{ 234 / 255.f, 146 / 255.f, 37 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 7, pos.y + pixelSize.y * 4 }, pixelSize, color, FLinearColor{ 193 / 255.f, 111 / 255.f, 28 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 7, pos.y + pixelSize.y * 5 }, pixelSize, color, FLinearColor{ 152 / 255.f, 89 / 255.f, 22 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 7, pos.y + pixelSize.y * 6 }, pixelSize, color, FLinearColor{ 110 / 255.f, 64 / 255.f, 16 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 7, pos.y + pixelSize.y * 7 }, pixelSize, color, FLinearColor{ 80 / 255.f, 47 / 255.f, 12 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 7, pos.y + pixelSize.y * 8 }, pixelSize, color, FLinearColor{ 82 / 255.f, 82 / 255.f, 82 / 255.f, 1.0f });
			}
			//8
			{
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 8, pos.y + pixelSize.y * 0 }, pixelSize, color, FLinearColor{ 247 / 255.f, 218 / 255.f, 170 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 8, pos.y + pixelSize.y * 1 }, pixelSize, color, FLinearColor{ 244 / 255.f, 200 / 255.f, 124 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 8, pos.y + pixelSize.y * 2 }, pixelSize, color, FLinearColor{ 241 / 255.f, 182 / 255.f, 77 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 8, pos.y + pixelSize.y * 3 }, pixelSize, color, FLinearColor{ 239 / 255.f, 174 / 255.f, 44 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 8, pos.y + pixelSize.y * 4 }, pixelSize, color, FLinearColor{ 196 / 255.f, 137 / 255.f, 34 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 8, pos.y + pixelSize.y * 5 }, pixelSize, color, FLinearColor{ 154 / 255.f, 108 / 255.f, 27 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 8, pos.y + pixelSize.y * 6 }, pixelSize, color, FLinearColor{ 111 / 255.f, 77 / 255.f, 19 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 8, pos.y + pixelSize.y * 7 }, pixelSize, color, FLinearColor{ 80 / 255.f, 56 / 255.f, 14 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 8, pos.y + pixelSize.y * 8 }, pixelSize, color, FLinearColor{ 54 / 255.f, 54 / 255.f, 54 / 255.f, 1.0f });
			}
			//9
			{
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 9, pos.y + pixelSize.y * 0 }, pixelSize, color, FLinearColor{ 254 / 255.f, 243 / 255.f, 187 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 9, pos.y + pixelSize.y * 1 }, pixelSize, color, FLinearColor{ 253 / 255.f, 237 / 255.f, 153 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 9, pos.y + pixelSize.y * 2 }, pixelSize, color, FLinearColor{ 253 / 255.f, 231 / 255.f, 117 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 9, pos.y + pixelSize.y * 3 }, pixelSize, color, FLinearColor{ 254 / 255.f, 232 / 255.f, 85 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 9, pos.y + pixelSize.y * 4 }, pixelSize, color, FLinearColor{ 242 / 255.f, 212 / 255.f, 53 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 9, pos.y + pixelSize.y * 5 }, pixelSize, color, FLinearColor{ 192 / 255.f, 169 / 255.f, 42 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 9, pos.y + pixelSize.y * 6 }, pixelSize, color, FLinearColor{ 138 / 255.f, 120 / 255.f, 30 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 9, pos.y + pixelSize.y * 7 }, pixelSize, color, FLinearColor{ 101 / 255.f, 87 / 255.f, 22 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 9, pos.y + pixelSize.y * 8 }, pixelSize, color, FLinearColor{ 29 / 255.f, 29 / 255.f, 29 / 255.f, 1.0f });
			}
			//10
			{
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 10, pos.y + pixelSize.y * 0 }, pixelSize, color, FLinearColor{ 247 / 255.f, 243 / 255.f, 185 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 10, pos.y + pixelSize.y * 1 }, pixelSize, color, FLinearColor{ 243 / 255.f, 239 / 255.f, 148 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 10, pos.y + pixelSize.y * 2 }, pixelSize, color, FLinearColor{ 239 / 255.f, 232 / 255.f, 111 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 10, pos.y + pixelSize.y * 3 }, pixelSize, color, FLinearColor{ 235 / 255.f, 229 / 255.f, 76 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 10, pos.y + pixelSize.y * 4 }, pixelSize, color, FLinearColor{ 208 / 255.f, 200 / 255.f, 55 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 10, pos.y + pixelSize.y * 5 }, pixelSize, color, FLinearColor{ 164 / 255.f, 157 / 255.f, 43 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 10, pos.y + pixelSize.y * 6 }, pixelSize, color, FLinearColor{ 118 / 255.f, 114 / 255.f, 31 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 10, pos.y + pixelSize.y * 7 }, pixelSize, color, FLinearColor{ 86 / 255.f, 82 / 255.f, 21 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 10, pos.y + pixelSize.y * 8 }, pixelSize, color, FLinearColor{ 9 / 255.f, 9 / 255.f, 9 / 255.f, 1.0f });
			}
			//11
			{
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 11, pos.y + pixelSize.y * 0 }, pixelSize, color, FLinearColor{ 218 / 255.f, 232 / 255.f, 182 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 11, pos.y + pixelSize.y * 1 }, pixelSize, color, FLinearColor{ 198 / 255.f, 221 / 255.f, 143 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 11, pos.y + pixelSize.y * 2 }, pixelSize, color, FLinearColor{ 181 / 255.f, 210 / 255.f, 103 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 11, pos.y + pixelSize.y * 3 }, pixelSize, color, FLinearColor{ 154 / 255.f, 186 / 255.f, 76 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 11, pos.y + pixelSize.y * 4 }, pixelSize, color, FLinearColor{ 130 / 255.f, 155 / 255.f, 64 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 11, pos.y + pixelSize.y * 5 }, pixelSize, color, FLinearColor{ 102 / 255.f, 121 / 255.f, 50 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 11, pos.y + pixelSize.y * 6 }, pixelSize, color, FLinearColor{ 74 / 255.f, 88 / 255.f, 36 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 11, pos.y + pixelSize.y * 7 }, pixelSize, color, FLinearColor{ 54 / 255.f, 64 / 255.f, 26 / 255.f, 1.0f });
				ColorPixel(FVector2D{ pos.x + pixelSize.x * 11, pos.y + pixelSize.y * 8 }, pixelSize, color, FLinearColor{ 0 / 255.f, 0 / 255.f, 0 / 255.f, 1.0f });
			}



			if (isHoveredPicker)
			{
				if (Input::IsMouseClicked(0, elements_count, false))
				{

				}
			}
			else
			{
				if (Input::IsMouseClicked(0, elements_count, false))
				{
					active_picker = -1;
					//hover_element = false;
				}
			}
		}
		else
		{
			//Bg
			if (isHovered)
			{
				drawFilledRect(FVector2D{ pos.x, pos.y }, size, size, Colors::Checkbox_Hovered);
				hover_element = true;
			}
			else
			{
				drawFilledRect(FVector2D{ pos.x, pos.y }, size, size, Colors::Checkbox_Idle);
			}

			//Color
			drawFilledRect(FVector2D{ pos.x + 4, pos.y + 4 }, size - 8, size - 8, *color);

			//Text
			FVector2D textPos = FVector2D{ pos.x + size + 5.0f, pos.y + size / 2 };
			TextLeft(name, textPos, FLinearColor{ 1.0f, 1.0f, 1.0f, 1.0f }, false);

			if (isHovered && Input::IsMouseClicked(0, elements_count, false))
			{
				saved_color = *color;
				active_picker = elements_count;
			}
		}


		sameLine = false;
		last_element_pos = pos;
		//last_element_size = size;
		if (first_element_pos.x == 0.0f)
			first_element_pos = pos;
	}


	void Render()
	{
		for (int i = 0; i < 128; i++)
		{
			if (PostRenderer::drawlist[i].type != -1)
			{
				//Filled Rect
				if (PostRenderer::drawlist[i].type == 1)
				{
					ZeroGUI::drawFilledRect(PostRenderer::drawlist[i].pos, PostRenderer::drawlist[i].size.x, PostRenderer::drawlist[i].size.y, PostRenderer::drawlist[i].color);
				}
				//TextLeft
				else if (PostRenderer::drawlist[i].type == 2)
				{
					ZeroGUI::TextLeft(PostRenderer::drawlist[i].name, PostRenderer::drawlist[i].pos, PostRenderer::drawlist[i].color, PostRenderer::drawlist[i].outline);
				}
				//TextCenter
				else if (PostRenderer::drawlist[i].type == 3)
				{
					ZeroGUI::TextCenter(PostRenderer::drawlist[i].name, PostRenderer::drawlist[i].pos, PostRenderer::drawlist[i].color, PostRenderer::drawlist[i].outline);
				}
				//Draw_Line
				else if (PostRenderer::drawlist[i].type == 4)
				{
					Draw_Line(PostRenderer::drawlist[i].from, PostRenderer::drawlist[i].to, PostRenderer::drawlist[i].thickness, PostRenderer::drawlist[i].color);
				}

				PostRenderer::drawlist[i].type = -1;
			}
		}
	}
}