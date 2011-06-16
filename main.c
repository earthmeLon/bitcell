//      main.c
//      
//      Copyright 2011 Daryl Tucker <daryl@Odin>
//      
//      This program is free software; you can redistribute it and/or modify
//      it under the terms of the GNU General Public License as published by
//      the Free Software Foundation; either version 2 of the License, or
//      (at your option) any later version.
//      
//      This program is distributed in the hope that it will be useful,
//      but WITHOUT ANY WARRANTY; without even the implied warranty of
//      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//      GNU General Public License for more details.
//      
//      You should have received a copy of the GNU General Public License
//      along with this program; if not, write to the Free Software
//      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
//      MA 02110-1301, USA.

#include <stdio.h>
#include <stdlib.h>
#include <libspe2.h>

int main(int argc, char **argv)
{
     int ret;

     spe_context_ptr_t spe;
     spe_program_handle_t *prog;
     unsigned int entry;
     spe_stop_info_t stop_info;

     prog = spe_image_open("hello_spe.elf");
     if (!prog) {
         perror("spe_image_open");
         exit(1);
     }

     spe = spe_context_create(0, NULL);
     if (!spe) {
         perror("spe_context_create");
         exit(1);
     }

     ret = spe_program_load(spe, prog);
     if (ret) {
         perror("spe_program_load");
         exit(1);
     }

     entry = SPE_DEFAULT_ENTRY;
     ret = spe_context_run(spe, &entry, 0, NULL, NULL, &stop_info);
     if (ret < 0) {
         perror("spe_context_run");
         exit(1);
     }

     ret = spe_context_destroy(spe);
     if (ret) {
         perror("spe_context_destroy");
         exit(1);
     }

     ret = spe_image_close(prog);
     if (ret) {
         perror("spe_image_close");
         exit(1);
     }

     return 0;
}

