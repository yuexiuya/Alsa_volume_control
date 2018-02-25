TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lasound


SOURCES += \
    main.cpp \
    AlsaVolCtl.cpp

#HEADERS += \
#    include/MediaInfoDLL.h \
#    include/mxcfb.h \
#    include/alsa/alisp.h \
#    include/alsa/asoundef.h \
#    include/alsa/asoundlib.h \
#    include/alsa/conf.h \
#    include/alsa/control.h \
#    include/alsa/control_external.h \
#    include/alsa/error.h \
#    include/alsa/global.h \
#    include/alsa/hwdep.h \
#    include/alsa/iatomic.h \
#    include/alsa/input.h \
#    include/alsa/mixer.h \
#    include/alsa/mixer_abst.h \
#    include/alsa/output.h \
#    include/alsa/pcm.h \
#    include/alsa/pcm_external.h \
#    include/alsa/pcm_extplug.h \
#    include/alsa/pcm_ioplug.h \
#    include/alsa/pcm_old.h \
#    include/alsa/pcm_plugin.h \
#    include/alsa/pcm_rate.h \
#    include/alsa/rawmidi.h \
#    include/alsa/seq.h \
#    include/alsa/seq_event.h \
#    include/alsa/seqmid.h \
#    include/alsa/seq_midi_event.h \
#    include/alsa/timer.h \
#    include/alsa/use-case.h \
#    include/alsa/version.h \
#    include/alsa/sound/asound_fm.h \
#    include/alsa/sound/emu10k1.h \
#    include/alsa/sound/hdsp.h \
#    include/alsa/sound/hdspm.h \
#    include/alsa/sound/sb16_csp.h \
#    include/alsa/sound/sscape_ioctl.h \
#    include/alsa/sound/type_compat.h

#include(imx6Env.pri)

HEADERS += \
    AlsaVolCtl.h


