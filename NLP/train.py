import pandas as pd
train_df = pd.read_csv('./data/train_set.csv', sep='\t')
print(train_df.head())