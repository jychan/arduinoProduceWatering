import time
millis = lambda: int(round(time.time() * 1000)) # get current time in ms

wateringInterval = 5 * 1000 # ms to wait between each watering
wateringDuration = 2 * 1000 # ms to water (ms to leave pump+lights+music on while watering)
wateringOn = False

startTime = millis()

while True:
    # start watering system
    if not wateringOn and millis() > startTime+wateringInterval:
        print "STARTING watering system"
        wateringOn = True
        startTime = millis()

        # code to activate pump here
        # code to activate lights here
        # code to activate music here


    # stop watering system
    if wateringOn and millis() > startTime + wateringDuration:
        print "STOPPING watering system"
        wateringOn = False
        startTime = millis()

        # code to stop pump here
        # code to stop lights here
        # code to stop music here


