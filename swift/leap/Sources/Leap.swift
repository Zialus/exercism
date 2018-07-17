struct Year {
    var calendarYear: Int

    var isLeapYear: Bool {

        let answer: Bool

        if calendarYear % 4 != 0 {
            answer = false
        } else if calendarYear % 400 == 0 {
            answer = true
        } else {
            answer = (calendarYear % 100 != 0)
        }

        return answer
    }
}
