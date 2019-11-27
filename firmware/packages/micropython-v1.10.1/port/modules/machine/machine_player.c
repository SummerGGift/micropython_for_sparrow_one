/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2019 SummerGift <SummerGift@qq.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <stdio.h>
#include <string.h>
#include "py/mphal.h"
#include "py/runtime.h"
#include "py/obj.h"
#include "py/builtin.h"

#define MICROPY_PY_MACHINE_PLAYER 1

#if MICROPY_PY_MACHINE_PLAYER

typedef struct _machine_player_obj_t {
    mp_obj_base_t base;
    const char* song_path;
} machine_player_obj_t;

const mp_obj_type_t machine_player_type;
extern const mp_print_t mp_plat_print;

STATIC void error_check(bool status, const char *msg) {
    if (!status) {
        nlr_raise(mp_obj_new_exception_msg(&mp_type_ValueError, msg));
    }
}

STATIC mp_obj_t machine_player_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *args) {
    machine_player_obj_t *self = m_new_obj(machine_player_obj_t);
    self->base.type = &machine_player_type;
    mp_arg_check_num(n_args, n_kw, 0, 0, true);
    return MP_OBJ_FROM_PTR(self);
}

//set a music to play
STATIC mp_obj_t player_opensong(mp_obj_t self_in, mp_obj_t path_obj) {
    const char* path = mp_obj_str_get_str(path_obj);
    machine_player_obj_t *self = self_in;
    self->song_path = path;

    mp_printf(&mp_plat_print, "song path=%s ", self->song_path);

    //Your code begin

    
    //Your code end

    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_2(player_opensong_obj, player_opensong);

//pause music playing
STATIC mp_obj_t player_pause(mp_obj_t self_in) {
    machine_player_obj_t *self = self_in;

    //Your code begin
    
    
    //Your code end

    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_1(player_pause_obj, player_pause);

//begin to play or continue to play music
STATIC mp_obj_t player_play(mp_obj_t self_in) {
    machine_player_obj_t *self = self_in;

    //Your code begin
    
    
    //Your code end

    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_1(player_play_obj, player_play);

//stop playing music
STATIC mp_obj_t player_set_volume(mp_obj_t volume_value_obj) {
    mp_int_t volume_value = mp_obj_get_int(volume_value_obj);
    
    //Your code begin
    
    
    //Your code end

    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_1(player_set_volume_obj, player_set_volume);

//stop playing, if this api is called, u should call opensong() to set a now song to play
STATIC mp_obj_t player_stop(mp_obj_t self_in) {
    machine_player_obj_t *self = self_in;
    mp_int_t ret_val;

    //Your code begin
    
    
    //Your code end

    return mp_obj_new_int(ret_val);
}
MP_DEFINE_CONST_FUN_OBJ_1(player_stop_obj, player_stop);

STATIC const mp_rom_map_elem_t player_module_globals_table[] = {
	{ MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_Player) },
	{ MP_ROM_QSTR(MP_QSTR_opensong), MP_ROM_PTR(&player_opensong_obj) },
	{ MP_ROM_QSTR(MP_QSTR_pause), MP_ROM_PTR(&player_pause_obj) },
	{ MP_ROM_QSTR(MP_QSTR_play), MP_ROM_PTR(&player_play_obj) },
	{ MP_ROM_QSTR(MP_QSTR_set_volume), MP_ROM_PTR(&player_set_volume_obj) },
	{ MP_ROM_QSTR(MP_QSTR_stop), MP_ROM_PTR(&player_stop_obj) },
};

STATIC MP_DEFINE_CONST_DICT(player_module_globals, player_module_globals_table);

const mp_obj_type_t machine_player_type = {
    { &mp_type_type },
    .name = MP_QSTR_Player,
    .make_new = machine_player_make_new,
    .locals_dict = (mp_obj_dict_t*)&player_module_globals,
};

#endif // MICROPY_PY_MACHINE_LCD
