import Foundation

class Gigasecond {

    var date: Date
    let formatter = DateFormatter.myDateFormat
    let gigasecond: TimeInterval = pow(10, 9)

    init?(from dateString: String) {

        if let date = formatter.date(from: dateString) {
            let laterDate = date + gigasecond
            self.date = laterDate
        } else {
            return nil
        }

    }

    var description: String {
        return formatter.string(from: self.date)
    }
}

extension DateFormatter {
    static let myDateFormat: DateFormatter = {
        let formatter = DateFormatter()
        formatter.dateFormat = "yyyy'-'MM'-'dd'T'HH':'mm':'ss"
        formatter.calendar = Calendar(identifier: .iso8601)
        formatter.timeZone = TimeZone(secondsFromGMT: 0)
        formatter.locale = Locale(identifier: "en_US_POSIX")
        return formatter
    }()
}
