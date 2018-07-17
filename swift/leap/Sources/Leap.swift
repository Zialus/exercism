class Year {
    var calendarYear: Int

    init(calendarYear: Int) {
        self.calendarYear = calendarYear
    }

    var isLeapYear: Bool {
        if calendarYear % 4 != 0 { return false }
        if calendarYear % 400 == 0 { return true }
        return (calendarYear % 100 != 0)
    }
}
