#pragma once
#include <cstdint>

namespace Leviathan
{

	using KeyCode = uint16_t;

	enum KeyCodes : KeyCode
	{
		// From glfw3.h
		Key_Space = 32,
		Key_Apostrophe = 39,	/* ' */
		Key_Comma = 44,			/* , */
		Key_Minus = 45,			/* - */
		Key_Period = 46,		/* . */
		Key_Slash = 47,			/* / */
		
		Key_D0 = 48,			/* 0 */
		Key_D1 = 49,			/* 1 */
		Key_D2 = 50,			/* 2 */
		Key_D3 = 51,			/* 3 */
		Key_D4 = 52,			/* 4 */
		Key_D5 = 53,			/* 5 */
		Key_D6 = 54,			/* 6 */
		Key_D7 = 55,			/* 7 */
		Key_D8 = 56,			/* 8 */
		Key_D9 = 57,			/* 9 */
		
		Key_Semicolon = 59,		/* ; */
		Key_Equal = 61,			/* = */

		//Letters (ASCII values)
		Key_A = 65,
		Key_B = 66,
		Key_C = 67,
		Key_D = 68,
		Key_E = 69,
		Key_F = 70,
		Key_G = 71,
		Key_H = 72,
		Key_I = 73,
		Key_J = 74,
		Key_K = 75,
		Key_L = 76,
		Key_M = 77,
		Key_N = 78,
		Key_O = 79,
		Key_P = 80,
		Key_Q = 81,
		Key_R = 82,
		Key_S = 83,
		Key_T = 84,
		Key_U = 85,
		Key_V = 86,
		Key_W = 87,
		Key_X = 88,
		Key_Y = 89,
		Key_Z = 90,

		Key_LeftBracket = 91,		/* [ */
		Key_Backslash = 92,			/* \ */
		Key_RightBracket = 93,		/* ] */
		Key_GraveAccent = 96,		/* ` */

		Key_World1 = 161,			/* non-US #1 */
		Key_World2 = 162,			/* non-US #2 */

		/* Function keys */
		Key_Escape = 256,
		Key_Enter = 257,
		Key_Tab = 258,
		Key_Backspace = 259,
		Key_Insert = 260,
		Key_Delete = 261,
		Key_Right = 262,
		Key_Left = 263,
		Key_Down = 264,
		Key_Up = 265,
		Key_PageUp = 266,
		Key_PageDown = 267,
		Key_Home = 268,
		Key_End = 269,
		Key_CapsLock = 280,
		Key_ScrollLock = 281,
		Key_NumLock = 282,
		Key_PrintScreen = 283,
		Key_Pause = 284,
		Key_F1 = 290,
		Key_F2 = 291,
		Key_F3 = 292,
		Key_F4 = 293,
		Key_F5 = 294,
		Key_F6 = 295,
		Key_F7 = 296,
		Key_F8 = 297,
		Key_F9 = 298,
		Key_F10 = 299,
		Key_F11 = 300,
		Key_F12 = 301,
		Key_F13 = 302,
		Key_F14 = 303,
		Key_F15 = 304,
		Key_F16 = 305,
		Key_F17 = 306,
		Key_F18 = 307,
		Key_F19 = 308,
		Key_F20 = 309,
		Key_F21 = 310,
		Key_F22 = 311,
		Key_F23 = 312,
		Key_F24 = 313,
		Key_F25 = 314,

		/* Keypad */
		Key_KP0 = 320,
		Key_KP1 = 321,
		Key_KP2 = 322,
		Key_KP3 = 323,
		Key_KP4 = 324,
		Key_KP5 = 325,
		Key_KP6 = 326,
		Key_KP7 = 327,
		Key_KP8 = 328,
		Key_KP9 = 329,
		Key_KPDecimal = 330,
		Key_KPDivide = 331,
		Key_KPMultiply = 332,
		Key_KPSubtract = 333,
		Key_KPAdd = 334,
		Key_KPEnter = 335,
		Key_KPEqual = 336,

		Key_LeftShift = 340,
		Key_LeftControl = 341,
		Key_LeftAlt = 342,
		Key_LeftSuper = 343,
		Key_RightShift = 344,
		Key_RightControl = 345,
		Key_RightAlt = 346,
		Key_RightSuper = 347,
		Key_Menu = 348
	};
}