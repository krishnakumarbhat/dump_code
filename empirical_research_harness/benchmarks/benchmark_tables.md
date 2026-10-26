## Ranked association backends

| F1 rank | Algorithm            | Basis                                       | Prec % | Rec % | F1 %  | Jacc % | IDSW | IDSW/1k | Loc m | ms/1k  | Deployment                         |
|---------|----------------------|---------------------------------------------|--------|-------|-------|--------|------|---------|-------|--------|------------------------------------|
| 1       | mahalanobis          | Chi-square Mahalanobis + Munkres            | 72.64  | 97.66 | 76.91 | 70.82  | 102  | 4.2     | 0.057 | 1269.8 | Best real-log F1 (opt-in)          |
| 2       | gospa                | GOSPA (c, p, alpha) optimization            | 72.51  | 97.52 | 76.77 | 70.61  | 237  | 9.7     | 0.043 | 1148.0 | FP/FN decomposition (opt-in)       |
| 3       | hungarian_normalized | Hard gates + normalized Euclidean Hungarian | 71.92  | 96.93 | 76.18 | 69.71  | 49   | 2.1     | 0.035 | 1142.4 | Production default (gate-faithful) |
| 4       | multi_scan           | Sliding-window trajectory association       | 71.92  | 96.93 | 76.18 | 69.71  | 73   | 3.1     | 0.035 | 2180.2 | Occlusion / dropouts (opt-in)      |
| 5       | obb_auction          | OBB + Doppler auction                       | 70.91  | 95.91 | 75.17 | 68.26  | 35   | 1.6     | 0.021 | 1628.7 | Extended objects (opt-in)          |

## F1 (%) per scenario

| Scene | mahalanobis | gospa  | hungarian_normalized | multi_scan | obb_auction |
|-------|-------------|--------|----------------------|------------|-------------|
| A     | 100.00      | 100.00 | 100.00               | 100.00     | 100.00      |
| B     | 100.00      | 100.00 | 100.00               | 100.00     | 100.00      |
| C     | 16.67       | 16.67  | 16.67                | 16.67      | 16.67       |
| D     | 80.00       | 80.00  | 80.00                | 80.00      | 80.00       |
| E     | 87.86       | 87.19  | 84.24                | 84.24      | 79.17       |

## Legacy baselines (uniform FP accounting)

| Algorithm      | Scene | TP    | FP    | FN    | Prec % | Rec %  | F1 %   | Swaps |
|----------------|-------|-------|-------|-------|--------|--------|--------|-------|
| legacy_id      | A     | 0     | 80    | 80    | 0.00   | 0.00   | 0.00   | 0     |
| greedy_nearest | A     | 80    | 0     | 0     | 100.00 | 100.00 | 100.00 | 0     |
| legacy_id      | B     | 20    | 10    | 10    | 66.67  | 66.67  | 66.67  | 0     |
| greedy_nearest | B     | 30    | 0     | 0     | 100.00 | 100.00 | 100.00 | 0     |
| legacy_id      | C     | 0     | 550   | 50    | 0.00   | 0.00   | 0.00   | 0     |
| greedy_nearest | C     | 50    | 500   | 0     | 9.09   | 100.00 | 16.67  | 0     |
| legacy_id      | D     | 0     | 24    | 16    | 0.00   | 0.00   | 0.00   | 0     |
| greedy_nearest | D     | 16    | 8     | 0     | 66.67  | 100.00 | 80.00  | 0     |
| legacy_id      | E     | 6110  | 21741 | 21480 | 21.94  | 22.15  | 22.04  | n/a   |
| greedy_nearest | E     | 23353 | 4498  | 4237  | 83.85  | 84.64  | 84.24  | n/a   |