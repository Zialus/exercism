import Foundation

enum SpeechPattern {
    case question, yell, nothing, anything
}

func hey(_ input: String) -> String {

    switch analyze(input) {
    case .question:
        return "Sure."// if you ask him a question.
    case .yell:
        return "Whoa, chill out!" // if you yell at him.
    case .nothing:
        return "Fine. Be that way!" // if you address him without actually saying anything.
    case .anything:
        return "Whatever." // to anything else.
    }

}

func analyze(_ input: String) -> SpeechPattern {
    guard let lastChar = input.last else {
        return .nothing // String.last! returns nil for empty strings
    }

    if input.uppercased() == input && input.rangeOfCharacter(from: CharacterSet.letters) != nil {
        return .yell // Must contain at least one letter. All letters must be uppercase
    } else if lastChar == "?" {
        return .question // Ends in ?
    } else if input.trimmingCharacters(in: CharacterSet.whitespaces) == "" {
        return .nothing // Empty or only whitespaces
    } else {
        return .anything
    }
}
