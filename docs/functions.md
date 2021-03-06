## Begin

Reset and initialize sensor to default state.

```Arduino
bool begin()
```
### Return

- A **boolean** result of initialization. (`true` / `false`)
<br /><br /><br />
***
<br />

## Set Gamma

Set filter to stabilize Euler angle output.

```Arduino
void setGamma(bool state)
```

### Parameters

- `bool` is logic of gamma correction on/off `state`. (Options: `true` / `false`)

<br /><br /><br />
***
<br />

## Set Light

Set filter to stabilize Euler angle output.

```Arduino
void setLight(bool state, bool mode, uint8_t pwm)
```

### Parameters

- First `bool` is logic of fill-light on/off `state`. (Options: `true` / `false`)

- Second `bool` is logic of auto-adjust `mode` on/off state. (Options: `true` / `false`)

- `uint8_t` is number of `pwm` of fill-light brightness, only works while auto-adjust mode is off.

<br /><br /><br />
***
<br />

## Get Color

get 8-bits **RGB** or **CMYK** format data.

```Arduino
uint8_t getColor(ColorType color)
```

### Parameters

- `ColorType` is a string of `color`. (Options: `R` / `G` / `B` / `C` / `M` / `Y` / `K`)

### Return

- An **uint8_t** number from `0` through `255`.
<br /><br /><br />
***
<br />

## Get Grayscale

get 8-bits **grayscale** data.

```Arduino
uint8_t getGrayscale()
```

### Return

- An **uint8_t** number from `0` through `255`.
<br /><br /><br />
***
<br />


## Get Color Number

get 1 of 14 types of color that auto-detect by the sensor.

```Arduino
uint8_t getColorNumber()
```

### Return

- An **uint8_t** number from `0` through `13`.

### Color number list

- 0 : Black
- 1 : White
- 2 : Cyan
- 3 : Ocean
- 4 : Blue
- 5 : Violet
- 6 : Magenta
- 7 : Raspberry
- 8 : Red
- 9 : Orange
- 10 : Yellow
- 11 : Spring Green
- 12 : Green
- 13 : Turquoise
