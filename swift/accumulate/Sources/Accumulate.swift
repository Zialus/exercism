extension Sequence {
    func accumulate<T>(_ function: (Self.Element) -> T) -> [T] {
        var result: [T] = []
        for elem in self {
            let res = function(elem)
            result.append(res)
        }
        return result
    }
}
