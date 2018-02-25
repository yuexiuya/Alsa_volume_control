#include <iostream>
#include <alsa/asoundlib.h>

using namespace std;

static snd_mixer_t *demoMixer = NULL;
static snd_mixer_elem_t *demoMixerElem = NULL;
static snd_mixer_selem_id_t *demoMixerElemID;

static long minVol = 0;
static long maxVol = 0;

int main(int argc, char *argv[])
{
    int ret;   // to save return value
    //(1) open a mixer
    ret = snd_mixer_open(&demoMixer, 0);
    if( ret < 0 ) {
        cout << " [ ERROR ] open mixer failed !!! " << endl;
        snd_mixer_close(demoMixer);
        return -1;
    }
    //(2) attach hardware + mixer
    ret = snd_mixer_attach(demoMixer, "default");
    if( ret < 0 ) {
        cout << " [ ERROR ] mixer attached failed !!! " << endl;
        snd_mixer_close(demoMixer);
        return -1;
    }
    //(3) register mixer
    ret = snd_mixer_selem_register(demoMixer, NULL, NULL);
    if( ret < 0 ) {
        cout << " [ ERROR ] mixer register failed !!! " << endl;
        snd_mixer_close(demoMixer);
        return -1;
    }
    //(4) load mixer
    ret = snd_mixer_load(demoMixer);
    if( ret < 0 ) {
        cout << " [ ERROR ] mixer load failed !!! " << endl;
        snd_mixer_close(demoMixer);
        return -1;
    }
    //(5) get mixer elem
    snd_mixer_elem_t *elem;
    for(elem=snd_mixer_first_elem(demoMixer); elem; elem=snd_mixer_elem_next(elem))
    {
        if (snd_mixer_elem_get_type(elem) == SND_MIXER_ELEM_SIMPLE &&
             snd_mixer_selem_is_active(elem)) // 找到可以用的, 激活的elem
        {
            const char * tmp = snd_mixer_selem_get_name(elem);
            printf("tmp = %s \n",tmp);

            if(strstr(tmp,"Master"))
            {
                printf("tmp111 \n");
                snd_mixer_selem_get_playback_volume_range(elem, &minVol, &maxVol);
                printf("minVol = %d, maxVold = %d \n",minVol, maxVol);
                snd_mixer_selem_set_playback_volume_all(elem, maxVol/2); // 设置音量为50
//                printf("minVol = %d, maxVold = %d \n",minVol, maxVol);
            }
        }
    }
    printf(" =======\n");
    //    snd_mixer_selem_id_alloca(&demoMixerElemID);
    //    cout<<"______"<<demoMixerElemID<<endl;
    //    snd_mixer_selem_id_set_index(demoMixerElemID, 0);
    //    snd_mixer_selem_id_set_name(demoMixerElemID, "hw00SoftVolume");
    //    snd_mixer_elem_t *elem;
//    demoMixerElem = snd_mixer_find_selem(demoMixer, demoMixerElemID);
//    if( demoMixerElem == NULL ) {
//        cout << " [ ERROR ] demoMixerElem find elem failed !!! " << endl;
//        snd_mixer_close(demoMixer);
//        return -1;
//    }
//    if(snd_mixer_selem_has_playback_volume(demoMixerElem))
//    {
//        snd_mixer_selem_get_playback_volume_range(demoMixerElem, &minVol, &maxVol);
//        printf("minVol = %d, maxVol = %d \n", minVol, maxVol);
//    }



    return 0;
}

