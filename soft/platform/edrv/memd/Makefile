## ----------------------------------------------------------- ##
## Don't touch the next line unless you know what you're doing.##
## ----------------------------------------------------------- ##
include ${SOFT_WORKDIR}/env/compilation/compilevars.mk

# Name of the module
LOCAL_NAME := platform/edrv/memd

LOCAL_API_DEPENDS := platform \
                     platform/base/common \
                     platform/chip/hal \
                     platform/chip/defs \
                     platform/base/sx \
                     platform/base/std \
					 platform/edrv \

# include the target definition here to know which libs to link to
include  ${SOFT_WORKDIR}/target/$(CT_TARGET)/target.def
# if CT_ROMULATOR is set to yes, the flash mapping emulated will be the 
# one corresponding to the FLSH_MODEL selected for the CT_TARGET, this model 
# can be overwritten by adding FLSH_MODEL=<model> to the make command line
# the actual driver used will be the romulator driver 
ifeq "${CT_ROMULATOR}" "yes"
LOCAL_EXPORT_FLAG += MEMD_USE_ROMULATOR=1
LOCAL_MODULE_DEPENDS := platform/edrv/memd/${FLSH_MODEL}_romu
else
LOCAL_MODULE_DEPENDS := platform/edrv/memd/${FLSH_MODEL}
endif

# This is a top-level module
IS_TOP_LEVEL := yes

# Generates the CoolWatcher headers automatically.
AUTO_XMD2H ?= yes

# Generate the revision (version) file automatically during the make process.
AUTO_GEN_REVISION_HEADER := yes

# Compilation mode for the version string.
LOCAL_EXPORT_FLAG += MEMD_FLSH_MODEL=${FLSH_MODEL}

## ------------------------------------------------------------------------- ##
##                         Source files                                      ##
## ------------------------------------------------------------------------- ##
S_SRC :=
C_SRC := memd_map.c memd_switch_mode.c
INPUT_FILES :=  

## ------------------------------------- ##
##  Do Not touch below this line         ##
## ------------------------------------- ##
include ${SOFT_WORKDIR}/env/compilation/compilerules.mk


