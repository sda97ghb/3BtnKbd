#ifndef LINUXCONSTANTS_H
#define LINUXCONSTANTS_H

#ifdef linux

#include <X11/Xlib.h>
#include <X11/keysym.h>

namespace MouseButton {
    static constexpr int Left = Button1;
    static constexpr int Right = Button3;
}

namespace Key {
    static constexpr int N0 = XK_0;
    static constexpr int N1 = XK_1;
    static constexpr int N2 = XK_2;
    static constexpr int N3 = XK_3;
    static constexpr int N4 = XK_4;
    static constexpr int N5 = XK_5;
    static constexpr int N6 = XK_6;
    static constexpr int N7 = XK_7;
    static constexpr int N8 = XK_8;
    static constexpr int N9 = XK_9;
    static constexpr int Q = XK_Q;
    static constexpr int W = XK_W;
    static constexpr int E = XK_E;
    static constexpr int R = XK_R;
    static constexpr int T = XK_T;
    static constexpr int Y = XK_Y;
    static constexpr int U = XK_U;
    static constexpr int I = XK_I;
    static constexpr int O = XK_O;
    static constexpr int P = XK_P;
    static constexpr int A = XK_A;
    static constexpr int S = XK_S;
    static constexpr int D = XK_D;
    static constexpr int F = XK_F;
    static constexpr int G = XK_G;
    static constexpr int H = XK_H;
    static constexpr int J = XK_J;
    static constexpr int K = XK_K;
    static constexpr int L = XK_L;
    static constexpr int Z = XK_Z;
    static constexpr int X = XK_X;
    static constexpr int C = XK_C;
    static constexpr int V = XK_V;
    static constexpr int B = XK_B;
    static constexpr int N = XK_N;
    static constexpr int M = XK_M;
    static constexpr int Space   = XK_space;
    static constexpr int Escape  = XK_Escape;
    static constexpr int Shift   = XK_Shift_L;
    static constexpr int Control = XK_Control_L;
    static constexpr int Alt     = XK_Alt_L;
    static constexpr int Enter   = XK_Return;
    static constexpr int Down    = XK_Down;
    static constexpr int Left    = XK_Left;
    static constexpr int Right   = XK_Right;
}

#endif // linux

#endif // LINUXCONSTANTS_H
