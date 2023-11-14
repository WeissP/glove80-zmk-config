#include <behaviors.dtsi>
/* Include all behaviour includes needed */
#include <dt-bindings/zmk/outputs.h>
#include <dt-bindings/zmk/keys.h>
#include <dt-bindings/zmk/bt.h>
#include <dt-bindings/zmk/rgb.h>
#include "./locale/keys_de.h"

#define LAYER_Base 0
#define LAYER_Shift 1
#define LAYER_Lower 2
#define LAYER_Shlower 3
#define LAYER_Sticky 4
#define LAYER_Magic 5

/* To deal with the situation where there is no Lower layer, to keep &lower happy */
#ifndef LAYER_Lower
#define LAYER_Lower 0
#endif

/ {
    /* Glove80 system behavior & macros */
    behaviors {
        // For the "layer" key, it'd nice to be able to use it as either a shift or a toggle.
        // Configure it as a tap dance, so the first tap (or hold) is a &mo and the second tap is a &to
        lower: lower {
            compatible = "zmk,behavior-tap-dance";
            label = "LAYER_TAP_DANCE";
            #binding-cells = <0>;
            tapping-term-ms = <200>;
            bindings = <&mo LAYER_Lower>, <&to LAYER_Lower>;
        };
    };
};

/ {
    macros {
        rptu_mail: rptu_mail {
            label = "RPTU_MAIL";
            compatible = "zmk,behavior-macro";
            #binding-cells = <0>;
            bindings
                = <&macro_tap &kp LC(DE_HASH)>
                , <&macro_tap &kp F &kp A &kp K &kp E>;
        };

        rptu_cs_mail: rptu_cs_mail {
            label = "rptu_cs_mail";
            compatible = "zmk,behavior-macro";
            #binding-cells = <0>;
            bindings
                = <&macro_tap &kp LC(DE_HASH)>
                , <&macro_tap &kp F &kp A &kp K &kp E>;
        };

        gmail: gmail {
            label = "gmail";
            compatible = "zmk,behavior-macro";
            #binding-cells = <0>;
            bindings
                = <&macro_tap &kp LC(DE_HASH)>
                , <&macro_tap &kp F &kp A &kp K &kp E>;
        };

        wangyi_mail: wangyi_mail {
            label = "wangyi_mail";
            compatible = "zmk,behavior-macro";
            #binding-cells = <0>;
            bindings
                = <&macro_tap &kp LC(DE_HASH)>
                , <&macro_tap &kp F &kp A &kp K &kp E>;
        };

        webde_mail: webde_mail {
            label = "webde_mail";
            compatible = "zmk,behavior-macro";
            #binding-cells = <0>;
            bindings
                = <&macro_tap &kp LC(DE_HASH)>
                , <&macro_tap &kp F &kp A &kp K &kp E>;
        };

        personal_tk: personal_tk {
            label = "personal_tk";
            compatible = "zmk,behavior-macro";
            #binding-cells = <0>;
            bindings
                = <&macro_tap &kp LC(DE_HASH)>
                , <&macro_tap &kp F &kp A &kp K &kp E>;
        };

        copy_all: copy_all {
            label = "COPY_ALL";
            compatible = "zmk,behavior-macro";
            #binding-cells = <0>;
            bindings
                = <&macro_tap &kp LC(A) &kp LC(C)>;
        };

        rgb_ug_status_macro: rgb_ug_status_macro {
            label = "RGB_UG_STATUS";
            compatible = "zmk,behavior-macro";
            #binding-cells = <0>;
            bindings
                = <&rgb_ug RGB_STATUS>;
        };

        bt_0: bt_0 {
            label = "BT_0";
            compatible = "zmk,behavior-macro";
            #binding-cells = <0>;
            bindings
                = <&out OUT_BLE>,
                  <&bt BT_SEL 0>;
        };

        bt_1: bt_1 {
            label = "BT_1";
            compatible = "zmk,behavior-macro";
            #binding-cells = <0>;
            bindings
                = <&out OUT_BLE>,
                  <&bt BT_SEL 1>;
        };

        bt_2: bt_2 {
            label = "BT_2";
            compatible = "zmk,behavior-macro";
            #binding-cells = <0>;
            bindings
                = <&out OUT_BLE>,
                  <&bt BT_SEL 2>;
        };

        bt_3: bt_3 {
            label = "BT_3";
            compatible = "zmk,behavior-macro";
            #binding-cells = <0>;
            bindings
                = <&out OUT_BLE>,
                  <&bt BT_SEL 3>;
        };
    };
};

/ {
    conditional_layers {
        compatible = "zmk,conditional-layers";
        tri_layer {
            if-layers = <LAYER_Shift LAYER_Lower>;
            then-layer = <LAYER_Shlower>;
        };
    };
};

&sl {
    release-after-ms = <5000>;
};

/ {
    magic: magic {
        compatible = "zmk,behavior-hold-tap";
        label = "MAGIC_HOLD_TAP";
        #binding-cells = <2>;
        flavor = "tap-preferred";
        tapping-term-ms = <200>;
        bindings = <&mo>, <&rgb_ug_status_macro>;
    };
};

    /* #define for key positions */
#define POS_LH_T1 52
#define POS_LH_T2 53
#define POS_LH_T3 54
#define POS_LH_T4 69
#define POS_LH_T5 70
#define POS_LH_T6 71
#define POS_LH_C1R2 15
#define POS_LH_C1R3 27
#define POS_LH_C1R4 39
#define POS_LH_C1R5 51
#define POS_LH_C2R1 4
#define POS_LH_C2R2 14
#define POS_LH_C2R3 26
#define POS_LH_C2R4 38
#define POS_LH_C2R5 50
#define POS_LH_C2R6 68
#define POS_LH_C3R1 3
#define POS_LH_C3R2 13
#define POS_LH_C3R3 25
#define POS_LH_C3R4 37
#define POS_LH_C3R5 49
#define POS_LH_C3R6 67
#define POS_LH_C4R1 2
#define POS_LH_C4R2 12
#define POS_LH_C4R3 24
#define POS_LH_C4R4 36
#define POS_LH_C4R5 48
#define POS_LH_C4R6 66
#define POS_LH_C5R1 1
#define POS_LH_C5R2 11
#define POS_LH_C5R3 23
#define POS_LH_C5R4 35
#define POS_LH_C5R5 47
#define POS_LH_C5R6 65
#define POS_LH_C6R1 0
#define POS_LH_C6R2 10
#define POS_LH_C6R3 22
#define POS_LH_C6R4 34
#define POS_LH_C6R5 46
#define POS_LH_C6R6 64
#define POS_RH_T1 57
#define POS_RH_T2 56
#define POS_RH_T3 55
#define POS_RH_T4 74
#define POS_RH_T5 73
#define POS_RH_T6 72
#define POS_RH_C1R2 16
#define POS_RH_C1R3 28
#define POS_RH_C1R4 40
#define POS_RH_C1R5 58
#define POS_RH_C2R1 5
#define POS_RH_C2R2 17
#define POS_RH_C2R3 29
#define POS_RH_C2R4 41
#define POS_RH_C2R5 59
#define POS_RH_C2R6 75
#define POS_RH_C3R1 6
#define POS_RH_C3R2 18
#define POS_RH_C3R3 30
#define POS_RH_C3R4 42
#define POS_RH_C3R5 60
#define POS_RH_C3R6 76
#define POS_RH_C4R1 7
#define POS_RH_C4R2 19
#define POS_RH_C4R3 31
#define POS_RH_C4R4 43
#define POS_RH_C4R5 61
#define POS_RH_C4R6 77
#define POS_RH_C5R1 8
#define POS_RH_C5R2 20
#define POS_RH_C5R3 32
#define POS_RH_C5R4 44
#define POS_RH_C5R5 62
#define POS_RH_C5R6 78
#define POS_RH_C6R1 9
#define POS_RH_C6R2 21
#define POS_RH_C6R3 33
#define POS_RH_C6R4 45
#define POS_RH_C6R5 63
#define POS_RH_C6R6 79

/ {
    keymap {
        compatible = "zmk,keymap";
        LAYER_Base {
        bindings = <
        &kp F5   &kp DE_CARET   &kp F15   &kp F16   &kp F11         &kp LG(N1)   &kp LG(N2)   &kp DE_SINGLE_QUOTE   &kp DE_LBRC   &kp DE_LBKT
        &kp DE_UNDERSCORE   &kp N0   &mt LALT DE_COLON   &mt LCTRL TAB   &kp DE_SLASH   &kp DE_SEMI   &kp DE_AMPS   &kp DE_BSLH   &kp DE_MINUS   &kp DE_DOUBLE_QUOTES   &kp DE_LEFT_PARENTHESIS   &kp DE_LT
        &kp LC(TAB)   &kp Q   &kp W   &kp E   &kp R   &kp T   &kp DE_Y   &kp U   &kp I   &kp O   &kp P   &kp DE_QMARK
        &kp LS(LC(TAB))   &kp A   &kp S   &kp D   &kp F   &kp G   &kp H   &kp J   &kp K   &kp L   &kp DE_EQUAL   &kp DE_GRAVE
        &copy_all   &kp DE_Z   &kp X   &kp C   &kp V   &kp B   &lt LAYER_Lower ENTER   &sl LAYER_Sticky   &kp LSHIFT   &kp F14   &mt LALT HOME   &kp SPACE   &kp N   &kp M   &kp COMMA   &kp DOT   &kp LC(LS(DE_PLUS))   &kp N1
        &kp LC(A)   &kp LC(V)   &kp LEFT   &kp RIGHT   &kp F17      &lt LAYER_Shift END   &kp BSPC   &magic LAYER_Magic 0   &kp LGUI   &kp DEL   &mt LCTRL ESC      &kp F6   &kp DOWN   &kp UP   &kp LC(C)   &kp N2
        >;
        };
        
        LAYER_Shift {
        bindings = <
        &trans   &kp DE_DLLR   &trans   &trans   &trans         &trans   &trans   &trans   &kp DE_RBRC   &kp DE_RBKT
        &trans   &trans   &kp LS(TAB)   &trans   &trans   &trans   &kp DE_PIPE   &kp DE_HASH   &kp DE_AT   &kp DE_SINGLE_QUOTE   &kp DE_RIGHT_PARENTHESIS   &kp DE_GT
        &trans   &kp LS(Q)   &kp LS(W)   &kp LS(E)   &kp LS(R)   &kp LS(T)   &kp LS(DE_Y)   &kp LS(U)   &kp LS(I)   &kp LS(O)   &kp LS(P)   &kp DE_EXCLAMATION
        &trans   &kp LS(A)   &kp LS(S)   &kp LS(D)   &kp LS(F)   &kp LS(G)   &kp LS(H)   &kp LS(J)   &kp LS(K)   &kp LS(L)   &kp SEMI   &kp DE_TILDE
        &trans   &kp LS(DE_Z)   &kp LS(X)   &kp LS(C)   &kp LS(V)   &kp LS(B)   &trans   &trans   &trans   &trans   &trans   &trans   &kp LS(N)   &kp LS(M)   &kp COMMA   &kp DOT   &kp FSLH   &kp PG_UP
        &trans   &kp LG(LEFT)   &kp LG(RIGHT)   &kp LEFT   &kp RIGHT      &trans   &trans   &trans   &trans   &trans   &trans      &kp LG(UP)   &kp LG(DOWN)   &kp LBKT   &kp RBKT   &kp PG_DN
        >;
        };
        
        LAYER_Lower {
        bindings = <
        &trans   &trans   &trans   &trans   &trans         &trans   &trans   &trans   &trans   &trans
        &trans   &trans   &kp LG(ESC)   &trans   &trans   &trans   &kp DE_COLON   &kp KP_NUM   &kp KP_EQUAL   &kp INT_YEN   &kp DE_EURO   &trans
        &trans   &trans   &trans   &trans   &trans   &trans   &kp DE_DEGREE   &kp KP_N7   &kp KP_N8   &kp KP_N9   &kp KP_PLUS   &trans
        &trans   &kp DE_A_UMLAUT   &kp DE_ESZETT   &kp DE_O_UMLAUT   &kp DE_U_UMLAUT   &trans   &kp DE_PERCENT   &kp KP_N4   &kp KP_N5   &kp KP_N6   &kp KP_MINUS   &trans
        &trans   &trans   &trans   &trans   &trans   &trans   &trans   &trans   &to 0   &trans   &trans   &trans   &kp DE_COMMA   &kp KP_N1   &kp KP_N2   &kp KP_N3   &kp KP_MULTIPLY   &trans
        &trans   &trans   &kp PG_UP   &kp PG_DN   &trans      &trans   &trans   &trans   &trans   &trans   &trans      &kp BSPC   &kp KP_N0   &kp DE_DOT   &kp KP_SLASH   &trans
        >;
        };
        
        LAYER_Shlower {
        bindings = <
        &trans   &trans   &trans   &trans   &trans         &trans   &trans   &trans   &trans   &trans
        &trans   &trans   &trans   &trans   &trans   &trans   &trans   &kp F10   &kp F11   &kp F12   &trans   &trans
        &trans   &trans   &trans   &trans   &trans   &trans   &trans   &kp F7   &kp F8   &kp F9   &trans   &trans
        &trans   &kp LS(DE_A_UMLAUT)   &kp DE_CAPITAL_ESZETT   &kp LS(DE_O_UMLAUT)   &kp LS(DE_U_UMLAUT)   &trans   &trans   &kp F4   &kp F5   &kp F6   &trans   &trans
        &trans   &trans   &trans   &trans   &trans   &trans   &trans   &trans   &trans   &trans   &trans   &trans   &trans   &kp F1   &kp F2   &kp F3   &trans   &trans
        &trans   &trans   &trans   &trans   &trans      &trans   &trans   &trans   &trans   &trans   &trans      &trans   &trans   &trans   &trans   &trans
        >;
        };
        
        LAYER_Sticky {
        bindings = <
        &trans   &trans   &trans   &trans   &trans         &trans   &trans   &trans   &trans   &trans
        &trans   &trans   &trans   &trans   &trans   &trans   &trans   &trans   &trans   &trans   &trans   &trans
        &trans   &trans   &webde_mail   &trans   &rptu_mail   &trans   &trans   &trans   &trans   &trans   &personal_tk   &trans
        &trans   &trans   &trans   &trans   &trans   &gmail   &trans   &trans   &trans   &trans   &trans   &trans
        &trans   &trans   &trans   &rptu_cs_mail   &kp LG(N4)   &trans   &trans   &trans   &trans   &trans   &trans   &trans   &trans   &wangyi_mail   &trans   &trans   &trans   &trans
        &trans   &trans   &trans   &trans   &trans      &trans   &trans   &trans   &trans   &trans   &trans      &trans   &trans   &trans   &trans   &trans
        >;
        };
        
        LAYER_Magic {
        bindings = <
        &bt BT_CLR   &none   &kp CAPSLOCK   &kp KP_NUMLOCK   &kp SCROLLLOCK         &none   &none   &none   &none   &bt BT_CLR_ALL
        &none   &none   &none   &none   &none   &none   &none   &none   &none   &none   &none   &none
        &none   &rgb_ug RGB_SPI   &rgb_ug RGB_SAI   &rgb_ug RGB_HUI   &rgb_ug RGB_BRI   &rgb_ug RGB_TOG   &none   &none   &none   &none   &none   &none
        &bootloader   &rgb_ug RGB_SPD   &rgb_ug RGB_SAD   &rgb_ug RGB_HUD   &rgb_ug RGB_BRD   &rgb_ug RGB_EFF   &none   &none   &none   &none   &none   &bootloader
        &sys_reset   &none   &none   &none   &none   &none   &bt_2   &bt_3   &out OUT_USB   &none   &none   &none   &none   &none   &none   &none   &none   &sys_reset
        &none   &none   &none   &none   &none      &bt_0   &bt_1   &none   &none   &none   &none      &none   &none   &none   &none   &none
        >;
        };
        
    };
};

/ {
    combos {
        compatible = "zmk,combos";
        combo_ctrlg {
            timeout-ms = <50>;
            key-positions = <POS_RH_C2R4 POS_RH_C3R4>;
            bindings = <&kp LC(G)>;
        };
    };
};
