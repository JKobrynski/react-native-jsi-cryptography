import { Platform } from 'react-native';

const LINKING_ERROR =
  `The package 'react-native-jsi-cryptography' doesn't seem to be linked. Make sure: \n\n` +
  Platform.select({ ios: "- You have run 'pod install'\n", default: '' }) +
  '- You rebuilt the app after installing the package\n' +
  '- You are not using Expo managed workflow\n';

const errorCondition = [
  // @ts-expect-error JSI unknown
  typeof global.md5,
  // @ts-expect-error JSI unknown
  typeof global.sha1,
  // @ts-expect-error JSI unknown
  typeof global.sha224,
  // @ts-expect-error JSI unknown
  typeof global.sha256,
  // @ts-expect-error JSI unknown
  typeof global.sha384,
  // @ts-expect-error JSI unknown
  typeof global.sha512,
].some((type) => type !== 'function');

if (errorCondition) {
  throw new Error(LINKING_ERROR);
}

export function md5(value: string): string {
  // @ts-expect-error JSI unknown
  return global.md5(value);
}

export function sha1(value: string): string {
  // @ts-expect-error JSI unknown
  return global.sha1(value);
}

export function sha224(value: string): string {
  // @ts-expect-error JSI unknown
  return global.sha224(value);
}

export function sha256(value: string): string {
  // @ts-expect-error JSI unknown
  return global.sha256(value);
}

export function sha384(value: string): string {
  // @ts-expect-error JSI unknown
  return global.sha384(value);
}

export function sha512(value: string): string {
  // @ts-expect-error JSI unknown
  return global.sha512(value);
}
