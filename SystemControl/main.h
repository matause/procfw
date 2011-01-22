#ifndef MAIN_H
#define MAIN_H

#include "systemctrl.h"
#include "systemctrl_se.h"
#include "systemctrl_private.h"

extern u32 psp_model;
extern u32 psp_fw_version;

int PatchExec1(unsigned char * buffer, int * check);
int PatchExec2(unsigned char * buffer, int * check);
int PatchExec3(unsigned char * buffer, int * check, int isplain, int checkresult);
int LoadCoreForKernel_01DB1EB3(unsigned char * buffer, int * check);

int _ProbeExec1(unsigned char * buffer, int * check);
int _ProbeExec2(unsigned char * buffer, int * check);
int _ProbeExec3(unsigned char * buffer, int * check); //GO ONLY

extern int (* ProbeExec3)(unsigned char * buffer, int * check); //GO ONLY
int _sceKernelCheckExecFile(unsigned char * buffer, int * check);

extern int (* PartitionCheck)(unsigned int * st0, unsigned int * check);
int _PartitionCheck(unsigned int * st0, unsigned int * check);

void syspatch_init();
void setup_module_handler(void);
void patch_sceLoaderCore(void);
void patch_sceLoadExec(void);
void load_rebootex_config(void);
void patch_sceMemlmd(void);
void patch_sceInterruptManager(void);
void resolve_removed_nid(SceModule *pMod);

#ifdef DEBUG
void validate_stub(SceModule *pMod);
void validate_stub_by_uid(int modid);
void setup_validate_stub(SceModule *mod);
#endif

void patch_umdcache(u32 text_addr);
void patch_partitions(void);
void unlock_high_memory(void);

void patch_npsignup(u32 text_addr);
void patch_npsignin(u32 text_addr);
void patch_np(u32 text_addr, u8 mayor, u8 minor);

void patch_sceMediaSync(u32 text_addr);
void patch_pspMarch33_Driver(u32 text_addr);

void load_plugin(void);
int load_start_module(char *path);

void usb_charge(void);

extern u32 p2_size;
extern u32 p8_size;
extern int high_memory_enabled;

//for sctrlHENLoadModuleOnReboot
extern char *g_insert_module_before;
extern void *g_insert_module_binary;
extern int g_insert_module_size;
extern int g_insert_module_flags;

int GetConfig(SEConfig *config);
int SetConfig(SEConfig *config);
void load_config(void);

void patch_module_for_updater(SceModule *mod);

extern SEConfig conf;

#endif
