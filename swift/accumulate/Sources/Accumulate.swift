extension Collection {
    func accumulate<T>(_ function: (Generator.Element) -> T?) -> [T] {
        var result: [T] = []
        for elem in self {
            if let res = function(elem) {
                result.append(res)
            }
        }
        return result
    }
}
