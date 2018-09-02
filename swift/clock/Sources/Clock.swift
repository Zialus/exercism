class Clock {
    var hours: Int
    var minutes: Int

    init(hours: Int, minutes: Int) {
        self.hours = hours
        self.minutes = minutes
        recalculate()
    }

    init(hours: Int) {
        self.hours = hours
        self.minutes = 0
        recalculate()
    }

    func minutesToClock(_ minutes: Int) -> (Int, Int) {
        let newHours = minutes / 60
        let newMinutes = minutes % 60

        return (newHours, newMinutes)
    }

    func recalculate() {
        fixOutsideTheClock()
        fixNegativeNumbers()
    }

    func fixOutsideTheClock() {
        // fix Minutes
        let (newHours, newMinutes) = minutesToClock(minutes)
        minutes = newMinutes
        hours += newHours
        // fix Hours
        hours %= 24
    }

    func fixNegativeNumbers() {
        if minutes < 0 {
            minutes = 60 + minutes
            hours -= 1
        }
        if hours < 0 {
            hours = 24 + hours
        }

    }

    func add(minutes: Int) -> Clock {
        let (newHours, newMinutes) = minutesToClock(minutes)
        let clock = Clock(hours: self.hours+newHours, minutes: self.minutes + newMinutes)
        return clock
    }

    func subtract(minutes: Int) -> Clock {
        let (newHours, newMinutes) = minutesToClock(minutes)
        let clock = Clock(hours: self.hours-newHours, minutes: self.minutes - newMinutes)
        return clock
    }

}

extension Clock: CustomStringConvertible {
    var description: String {
        let hoursString = "\(hours)".leftPadding(toLength: 2, withPad: "0")
        let minutesString = "\(minutes)".leftPadding(toLength: 2, withPad: "0")
        return hoursString + ":" + minutesString
    }
}

extension Clock: Equatable {
    static func == (lhs: Clock, rhs: Clock) -> Bool {
        return lhs.hours == rhs.hours && lhs.minutes == rhs.minutes
    }
}

extension String {
    func leftPadding(toLength: Int, withPad character: Character) -> String {
        let stringLength = self.count
        if stringLength < toLength {
            return String(repeatElement(character, count: toLength - stringLength)) + self
        } else {
            return String(self.suffix(toLength))
        }
    }
}
