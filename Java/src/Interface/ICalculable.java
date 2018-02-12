package Interface;

public interface ICalculable<T> {
    T sum(T other);

    T sub(T other);

    T mul(T other);

    T div(T other);
}