## ----------------------------------------------------------- ##
## Don't touch the next line unless you know what you're doing.##
## ----------------------------------------------------------- ##
include ${SOFT_WORKDIR}/env/compilation/compilevars.mk

# Name of the module
LOCAL_NAME := platform/svc/utraces

# list all modules APIs that are neccessary to compile this module
LOCAL_API_DEPENDS ?= platform                           \
                     platform/svc/uctls                 \
                     platform/svc/umss                  \
                     platform/svc/uvideos                  \
                     platform/chip/hal                  \
                     platform/chip/boot                 \
	                 platform/chip/regs/${CT_ASIC}      \
                     platform/chip/defs                 \
                     platform/base/sx

# list all the modules that need to be compiled prior to using this module
LOCAL_MODULE_DEPENDS ?=

## ------------------------------------ ##
## 	Add your custom flags here          ##
## ------------------------------------ ##

LOCAL_EXPORT_FLAG +=

## ------------------------------------- ##
##	List all your sources here           ##
## ------------------------------------- ##
include src/make.srcs

## ------------------------------------- ##
##  Do Not touch below this line         ##
## ------------------------------------- ##
include ${SOFT_WORKDIR}/env/compilation/compilerules.mk
