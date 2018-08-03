class SpaceAge {

    let ageInSeconds: Int

    init(_ ageInSeconds: Int) {
        self.ageInSeconds = ageInSeconds
    }

    var seconds: Int {
        return ageInSeconds
    }

    var years: Double {
        return (Double(ageInSeconds) / 60 / 60 / 24 / 365.25)
    }

    var onEarth: Double {
        return (years / 1)
    }
    var onMercury: Double {
        return (years / 0.2408467)
    }
    var onVenus: Double {
        return (years / 0.61519726)
    }
    var onMars: Double {
        return (years / 1.8808158)
    }
    var onJupiter: Double {
        return (years / 11.862615)
    }
    var onSaturn: Double {
        return (years / 29.447498)
    }
    var onUranus: Double {
        return (years / 84.016846)
    }
    var onNeptune: Double {
        return (years / 164.79132)
    }
}
