1) Identify Active Entities (2nd init AE)
      - patient
      - nurse
      - doctor

2) Shared memory (1º)
      - pfifo 

3) Direct communication between AE (3rd)
      - partial sync
      - doctor(up/broadcast) -> patient(down/wait)
