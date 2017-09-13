# h5_cPlusPlus_test.py -- explore the organization of file train.h5 to assist C++ project in loading data
# from Two Sigma Financial Modeling Challenge on Kaggle

import pandas as pd
import h5py
h5py.run_tests()

# Use h5py to read data from .h5 file
# HDF5 group
def printname(name):
    return print(name)

f = h5py.File("../input/train.h5", mode="r", driver=None)
f.visit(printname)  # prints members of file
# train
# train/axis0
# train/axis1
# train/block0_items
# train/block0_values
# train/block1_items
# train/block1_values

# The listed organization of train.h5 helped loading the data in C++

dset = f["train"]
dset_axis0 = f['/train/axis0']
print(dset_axis0.value)
# array([b'id', b'timestamp', b'derived_0', b'derived_1', b'derived_2',
#        b'derived_3', b'derived_4', b'fundamental_0', b'fundamental_1',
#        b'fundamental_2', b'fundamental_3', b'fundamental_5',
#        b'fundamental_6', b'fundamental_7', b'fundamental_8',
#        b'fundamental_9', b'fundamental_10', b'fundamental_11',
#        b'fundamental_12', b'fundamental_13', b'fundamental_14',
#        b'fundamental_15', b'fundamental_16', b'fundamental_17',
#        b'fundamental_18', b'fundamental_19', b'fundamental_20',
#        b'fundamental_21', b'fundamental_22', b'fundamental_23',
#        b'fundamental_24', b'fundamental_25', b'fundamental_26',
#        b'fundamental_27', b'fundamental_28', b'fundamental_29',
#        b'fundamental_30', b'fundamental_31', b'fundamental_32',
#        b'fundamental_33', b'fundamental_34', b'fundamental_35',
#        b'fundamental_36', b'fundamental_37', b'fundamental_38',
#        b'fundamental_39', b'fundamental_40', b'fundamental_41',
#        b'fundamental_42', b'fundamental_43', b'fundamental_44',
#        b'fundamental_45', b'fundamental_46', b'fundamental_47',
#        b'fundamental_48', b'fundamental_49', b'fundamental_50',
#        b'fundamental_51', b'fundamental_52', b'fundamental_53',
#        b'fundamental_54', b'fundamental_55', b'fundamental_56',
#        b'fundamental_57', b'fundamental_58', b'fundamental_59',
#        b'fundamental_60', b'fundamental_61', b'fundamental_62',
#        b'fundamental_63', b'technical_0', b'technical_1', b'technical_2',
#        b'technical_3', b'technical_5', b'technical_6', b'technical_7',
#        b'technical_9', b'technical_10', b'technical_11', b'technical_12',
#        b'technical_13', b'technical_14', b'technical_16', b'technical_17',
#        b'technical_18', b'technical_19', b'technical_20', b'technical_21',
#        b'technical_22', b'technical_24', b'technical_25', b'technical_27',
#        b'technical_28', b'technical_29', b'technical_30', b'technical_31',
#        b'technical_32', b'technical_33', b'technical_34', b'technical_35',
#        b'technical_36', b'technical_37', b'technical_38', b'technical_39',
#        b'technical_40', b'technical_41', b'technical_42', b'technical_43',
#        b'technical_44', b'y'],
#       dtype='|S14')
dset_axis1 = f['/train/axis1']
print(dset_axis1.value)
# Out[86]: array([      0,       1,       2, ..., 1710753, 1710754, 1710755])
dset_block0_items = f['/train/block0_items']
print(dset_block0_items.value)
# array([b'id', b'timestamp'],
#       dtype='|S9')
dset_block0_values = f['/train/block0_values']
print(dset_block0_values.value)
# array([[  10,    0],
#        [  11,    0],
#        [  12,    0],
#        ...,
#        [2154, 1812],
#        [2156, 1812],
#        [2158, 1812]], dtype=int16)
dset_block1_items = f['/train/block1_items']
print(dset_block1_items.value)
# array([b'derived_0', b'derived_1', b'derived_2', b'derived_3',
#        b'derived_4', b'fundamental_0', b'fundamental_1', b'fundamental_2',
#        b'fundamental_3', b'fundamental_5', b'fundamental_6',
#        b'fundamental_7', b'fundamental_8', b'fundamental_9',
#        b'fundamental_10', b'fundamental_11', b'fundamental_12',
#        b'fundamental_13', b'fundamental_14', b'fundamental_15',
#        b'fundamental_16', b'fundamental_17', b'fundamental_18',
#        b'fundamental_19', b'fundamental_20', b'fundamental_21',
#        b'fundamental_22', b'fundamental_23', b'fundamental_24',
#        b'fundamental_25', b'fundamental_26', b'fundamental_27',
#        b'fundamental_28', b'fundamental_29', b'fundamental_30',
#        b'fundamental_31', b'fundamental_32', b'fundamental_33',
#        b'fundamental_34', b'fundamental_35', b'fundamental_36',
#        b'fundamental_37', b'fundamental_38', b'fundamental_39',
#        b'fundamental_40', b'fundamental_41', b'fundamental_42',
#        b'fundamental_43', b'fundamental_44', b'fundamental_45',
#        b'fundamental_46', b'fundamental_47', b'fundamental_48',
#        b'fundamental_49', b'fundamental_50', b'fundamental_51',
#        b'fundamental_52', b'fundamental_53', b'fundamental_54',
#        b'fundamental_55', b'fundamental_56', b'fundamental_57',
#        b'fundamental_58', b'fundamental_59', b'fundamental_60',
#        b'fundamental_61', b'fundamental_62', b'fundamental_63',
#        b'technical_0', b'technical_1', b'technical_2', b'technical_3',
#        b'technical_5', b'technical_6', b'technical_7', b'technical_9',
#        b'technical_10', b'technical_11', b'technical_12', b'technical_13',
#        b'technical_14', b'technical_16', b'technical_17', b'technical_18',
#        b'technical_19', b'technical_20', b'technical_21', b'technical_22',
#        b'technical_24', b'technical_25', b'technical_27', b'technical_28',
#        b'technical_29', b'technical_30', b'technical_31', b'technical_32',
#        b'technical_33', b'technical_34', b'technical_35', b'technical_36',
#        b'technical_37', b'technical_38', b'technical_39', b'technical_40',
#        b'technical_41', b'technical_42', b'technical_43', b'technical_44',
#        b'y'],
#       dtype='|S14')
dset_block1_values = f['/train/block1_values']
print(dset_block1_values.value)
# array([[  3.70326221e-01,  -6.31639920e-03,   2.22831085e-01, ...,
#          -2.00000000e+00,              nan,  -1.17534492e-02],
#        [  1.47646843e-02,  -3.80642191e-02,  -1.74248777e-02, ...,
#          -2.00000000e+00,              nan,  -1.24013668e-03],
#        [ -1.06217954e-02,  -5.05770668e-02,   3.37957478e+00, ...,
#          -2.00000000e+00,              nan,  -2.09395438e-02],
#        ...,
#        [ -7.79296756e-02,  -3.87479812e-02,  -3.18590663e-02, ...,
#          -1.26681998e-11,   3.08159590e-02,  -6.85155625e-03],
#        [ -2.69845217e-01,  -5.32164471e-03,              nan, ...,
#          -1.99925995e+00,  -1.17062824e-02,  -7.84564996e-04],
#        [             nan,              nan,              nan, ...,
#           0.00000000e+00,              nan,   3.49700986e-03]], dtype=float32)

''' Pandas Data Frame to Load .h5 File '''
# Use python Pandas to read data from .h5 file
# Load the data from the HDF5 file instead of csv. The file consist only of training data.
# with pd.HDFStore("../input/train.h5", "r") as train:
# Training data

# Test if the .h5 has been modified while debugging in C++
with pd.HDFStore("../input/train.h5", "r") as train:
    df = train.get("train")

# Test python Pandas combability with .h5 file that works in C++
with pd.HDFStore("/pathToFile/Select.h5", "r") as train_select:
    df_select = train_select.get("Matrix in file")
