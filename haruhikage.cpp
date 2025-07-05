#include <windows.h>

int note_to_freq(char note) {
    switch(note) {
        case 's': return 196;//低音so
        case '1': return 262; // C4
        case '2': return 294; // D4
        case '3': return 330; // E4
        case '4': return 349; // F4
        case '5': return 392; // G4
        case '6': return 440; // A4
        case '7': return 494; // B4
        case 'i': return 523; // C5
        default:  return 0;   // 休止符或无效
    }
}

int main() {
    char melody[] = "ss|332432|2211432|21123.|0.35ii|7650524|4330s|43235|1.001|21.1151";
    int default_duration = 500;

    for (int i = 0; melody[i] != '\0'; i++) {
        char c = melody[i];
        if (c == '|' || c == ' ') continue;

        int duration = default_duration;
        if (melody[i+1] == '.') {
            duration *= 1.5;
            i++;
        }

        int freq = note_to_freq(c);
        if (freq > 0) {
            Beep(freq, duration);
        } else if (c == '0') {
            Sleep(duration);
        }
    }

    return 0;
}