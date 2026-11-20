#include <iostream>
class AudioBuffer {
    int* samples; int capacity;
public:
    explicit AudioBuffer(int n):samples(new int[n]),capacity(n){for(int i=0;i<n;++i)samples[i]=i*10;std::cout<<"Allocated "<<capacity<<" samples\n";}
    AudioBuffer(const AudioBuffer& o):samples(new int[o.capacity]),capacity(o.capacity){for(int i=0;i<capacity;++i)samples[i]=o.samples[i];std::cout<<"Deep copy allocated "<<capacity<<" samples\n";}
    ~AudioBuffer(){std::cout<<"Released "<<capacity<<" samples\n";delete[] samples;}
    int sample(int i)const{return samples[i];}
};
void processAudio(AudioBuffer b){std::cout<<"Processing sample 0: "<<b.sample(0)<<'\n';}
int main(){AudioBuffer track(5);processAudio(track);std::cout<<"Back in main, sample 0: "<<track.sample(0)<<'\n';}