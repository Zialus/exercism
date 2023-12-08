public class Lasagna {
    public static final int TIME_PER_LAYER = 2;

    public int expectedMinutesInOven() {
        return 40;
    }

    public int remainingMinutesInOven(int currentTime) {
        final int expectedMinutesInOven = expectedMinutesInOven();

        if (currentTime > expectedMinutesInOven) {
            throw new IllegalArgumentException();
        }

        return expectedMinutesInOven - currentTime;
    }

    public int preparationTimeInMinutes(int layers) {
        if (layers < 1) {
            throw new IllegalArgumentException();
        }
        return layers * TIME_PER_LAYER;
    }

    public int totalTimeInMinutes(int layers, int cookingTime) {
        if (layers < 1) {
            throw new IllegalArgumentException();
        }
        return preparationTimeInMinutes(layers) + cookingTime;
    }
}
