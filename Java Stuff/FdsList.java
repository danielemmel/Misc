package de.maibornwolff.fpjava.session5.list.exercise;

import de.maibornwolff.fpjava.session5.list.exercise.FdsList.Cons;
import de.maibornwolff.fpjava.session5.list.exercise.FdsList.Nil;
import java.util.Arrays;
import lombok.Getter;
import lombok.Setter;

public sealed interface FdsList<T> permits Nil, Cons {

  static <T> FdsList<T> of(T... values) {
    if (values.length == 0) {
      return new Nil();
    }

    Cons<T> nextList = new Cons<>(values[0]);
    FdsList<T> subList = of(removeFirstFromArray(values));
    nextList.setNext(subList);
    return nextList;
  }


  static <T> boolean eq(FdsList<T> list1, FdsList<T> list2) {
    return switch (list1) {
      case Nil nil1 -> (list2.getClass() == Nil.class);
      case Cons<T> cons1 -> (list2.getClass() == Cons.class) && Cons.eq(cons1, (Cons<T>) list2);
    };
  }

  final class Nil<T> implements FdsList<T> {

  }

  @Getter
  @Setter
  final class Cons<T> implements FdsList<T> {

    private T head;
    private FdsList<T> next;

    public Cons(T head) {
      this.head = head;
    }

    public static <T> boolean eq(Cons<T> cons1, Cons<T> cons2) {
      if (cons1 == cons2) {
        return true;
      }
      return cons1.getHead().equals(cons2.getHead()) && FdsList.eq(cons1.getNext(), cons2.getNext());
    }
  }

  private static <T> T[] removeFirstFromArray(T[] values) {
    assert values.length > 0;
    return Arrays.copyOfRange(values, 1, values.length);
  }
}
