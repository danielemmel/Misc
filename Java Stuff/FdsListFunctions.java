package de.maibornwolff.fpjava.session5.list.exercise;

import de.maibornwolff.fpjava.session5.list.exercise.FdsList.Cons;
import de.maibornwolff.fpjava.session5.list.exercise.FdsList.Nil;
import java.util.ArrayList;
import java.util.List;
import java.util.function.Predicate;

public class FdsListFunctions {

  public static <T> int length(FdsList<T> list) {
    return lengthRecursive(list, 0);
  }

  public static <T> FdsList<T> filterBy(FdsList<T> list, Predicate<T> predicate) {
    return filterByRecursive(list, predicate, new ArrayList<>());
  }

  private static <T> int lengthRecursive(FdsList<T> list, int subTotal) {
    return switch (list) {
      case Nil nil -> subTotal;
      case Cons<T> cons -> lengthRecursive(cons.getNext(), subTotal + 1);
    };
  }

  public static <T> FdsList<T> filterByRecursive(FdsList<T> list, Predicate<T> predicate, List<T> results) {
    return switch (list) {
      case Nil nil -> FdsList.of((T[]) results.toArray());
      case Cons<T> cons -> {
        if (predicate.test(cons.getHead())) {
          yield filterByRecursive(cons.getNext(), predicate,
              concatElementToList(results, cons.getHead()));
        } else {
          yield filterByRecursive(cons.getNext(), predicate, results);
        }
      }
    };
  }

  private static <T> List<T> concatElementToList(List<T> list, T elem) {
    List<T> newList = new ArrayList<>(list);
    newList.add(elem);
    return newList;
  }
}
