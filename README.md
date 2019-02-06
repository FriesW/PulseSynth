# PulseSynth

Listen to your heart beat.

## Setup
Arduino reads analog signal from a pulse sensor and sends it over USB serial.
Python script turns serial into UDP messages.
PureData script receives UDP messages and synthesizes audio.

## Parts

* Hardware
  * Arduino Nano or compatible
  * [PulseSensor](https://pulsesensor.com/)
* Software
  * Python 3+
  * [PySerial](https://pypi.org/project/pyserial/)
  * [Pd (Vanilla)](https://puredata.info/)

## Credits

Core synth patches from
[LovelyHeart](https://github.com/Limulo/LovelyHeart) and [HeartBeater](https://github.com/Limulo/HeartBeater)
by [Limulo](https://github.com/Limulo).

SuperTap tempo tap patch from a [forum post](https://forum.pdpatchrepo.info/topic/1494/tap-tempo/2)
by [domien](https://forum.pdpatchrepo.info/user/domien).

## License

Outside of the GPL license on Limulo's patches and the uncertain status of the SuperTap patch, the [WTFPL license](http://www.wtfpl.net/) applies.
