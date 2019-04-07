#!/usr/bin/env python3
# -*- coding: utf-8 -*-
class Barber():
  waiting = 0
  mutex = 1
  N = 15
  total = 30
  # N 为座椅数量，total 为总顾客数
  CM = 0
  BB = 0
  status = list()
  for x in range(0, total):
    status[x] = 0
  # status[x] 用来表示某位顾客是否已经理发，0 为未理发，1 为已理发

  def barber(i):
    wait(mutex)
    if waiting < N:
      waiting += 1
      signal(mutex)
      signal(CM)
      wait(BB)
      # Cut Hair
      s[i] = 1
    else:
      signal(mutex)

  def customer():
    wait(CM)
    wait(mutex)
    waiting -= 1
    signal(mutex)
    signal(BB)

def cm():
  while total:
    Barber.barber(total)
    total -= 1

def bb():
  while true:
    Barber.customer();

def main():
  cm()
  bb()

if __name__ == '__main__':
  main()