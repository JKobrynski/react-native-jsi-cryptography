import * as React from 'react';

import { StyleSheet, View, Text } from 'react-native';
// import { multiply } from 'react-native-jsi-cryptography';

export default function App() {
  // const [result, setResult] = React.useState<number | undefined>();

  // React.useEffect(() => {
  //   multiply(3, 7).then(setResult);
  // }, []);

  return (
    <View style={styles.container}>
      <Text>sha1: {sha1('grape')}</Text>
      <Text>md5: {md5('grape')}</Text>
      <Text>sha224: {sha224('grape')}</Text>
      <Text>sha256: {sha256('grape')}</Text>
      <Text>sha384: {sha384('grape')}</Text>
      <Text>sha512: {sha512('grape')}</Text>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
  },
  box: {
    width: 60,
    height: 60,
    marginVertical: 20,
  },
});
