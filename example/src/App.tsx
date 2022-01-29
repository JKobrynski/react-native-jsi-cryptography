import React, { useState } from 'react';
import {
  StyleSheet,
  View,
  Text,
  TouchableOpacity,
  TextInput,
} from 'react-native';
import {
  md5,
  sha1,
  sha224,
  sha256,
  sha384,
  sha512,
} from 'react-native-jsi-cryptography';

const functions = [
  'sha1',
  'md5',
  'sha224',
  'sha256',
  'sha384',
  'sha512',
] as const;

type Method = typeof functions[number];

const callMethod = (method: Method, value: string): string => {
  switch (method) {
    case 'sha1':
      return sha1(value);
    case 'md5':
      return md5(value);
    case 'sha224':
      return sha224(value);
    case 'sha256':
      return sha256(value);
    case 'sha384':
      return sha384(value);
    case 'sha512':
      return sha512(value);
  }
};

export default function App() {
  const [activeMethod, setActiveMethod] = useState<Method>('sha1');
  const [value, setValue] = useState('example');

  const onPress = (method: Method) => setActiveMethod(method);

  return (
    <View style={styles.container}>
      <View style={styles.flexed}>
        <Text style={styles.activeMethod}>{activeMethod}</Text>
        <Text>{callMethod(activeMethod, value)}</Text>
      </View>
      <View style={styles.flexed}>
        <TextInput
          value={value}
          onChangeText={setValue}
          style={styles.input}
          autoCapitalize="none"
        />
      </View>
      <View style={styles.flexed}>
        <View style={styles.row}>
          {functions.map((item) => (
            <TouchableOpacity
              key={item}
              onPress={() => onPress(item)}
              style={
                activeMethod === item
                  ? styles.activeVariantWrapper
                  : styles.variantWrapper
              }
            >
              <Text
                style={
                  activeMethod === item ? styles.activeVariant : styles.variant
                }
              >
                {item}
              </Text>
            </TouchableOpacity>
          ))}
        </View>
      </View>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
    paddingHorizontal: 24,
    paddingVertical: 100,
  },
  row: {
    flexDirection: 'row',
    alignItems: 'center',
    justifyContent: 'space-between',
    width: '100%',
    flexWrap: 'wrap',
  },
  flexed: {
    flex: 1,
    width: '100%',
    alignItems: 'center',
    justifyContent: 'center',
  },
  activeMethod: {
    fontSize: 32,
    fontWeight: '600',
    marginBottom: 40,
  },
  variantWrapper: {
    width: '28%',
    alignItems: 'center',
    marginBottom: 32,
    backgroundColor: '#eee',
    paddingVertical: 12,
    borderRadius: 16,
  },
  activeVariantWrapper: {
    width: '28%',
    alignItems: 'center',
    marginBottom: 32,
    backgroundColor: '#000',
    paddingVertical: 12,
    borderRadius: 16,
  },
  variant: {
    fontSize: 16,
    color: '#000',
    fontWeight: '500',
  },
  activeVariant: {
    fontSize: 16,
    color: '#fff',
    fontWeight: '500',
  },
  input: {
    width: '100%',
    borderBottomWidth: StyleSheet.hairlineWidth,
    fontSize: 20,
  },
});
