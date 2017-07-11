# Ecliptic watchface for Pebble smartwatch

Ecliptic displays positions of the Sun, the Moon and five brightest planets of the solar system that are visible with the naked eye. You can change the background color, enable hourly vibrations and lost connection notification in settings.


![ecliptic basalt](https://www.filepicker.io/api/file/ojEuJr9jS6CpiEqvh0Fq)

The Sun is always drawn on top of the ecliptic circle. To the left of the Sun you see planets that are currently visible in the evening after the sunset. To the right there are planets you can see in the morning before the sunrise. Planets in the bottom part of the screen are visible all night long.

### Legend:
* ☉ - Sun
* ☿ - Mercury
* ♀ - Venus
* ♂ - Mars
* ♃ - Jupiter
* ♄ - Saturn

The Moon glyph changes according to the current phase.

Planetary data isn't loaded from the Internet. Orbital elements of each displayed celestial body are built-in and all calculations are performed by the Pebble processor. GPS data isn't required because the Ecliptic code operates with ecliptic coordinates that do not depend on your current location (unless you are an astronaut in space far away from Earth).
