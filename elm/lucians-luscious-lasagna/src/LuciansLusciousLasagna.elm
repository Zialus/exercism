module LuciansLusciousLasagna exposing (elapsedTimeInMinutes, expectedMinutesInOven, preparationTimeInMinutes)


expectedMinutesInOven : number
expectedMinutesInOven =
    40


preparationTimeInMinutes : number -> number
preparationTimeInMinutes nLayers =
    nLayers * 2


elapsedTimeInMinutes : number -> number -> number
elapsedTimeInMinutes nLayers nMinutesInOven =
    preparationTimeInMinutes nLayers + nMinutesInOven
